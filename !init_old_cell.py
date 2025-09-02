from neuron import h
import os
import sys
sys.path.append("/Users/sandek/CA1Sim")  # so Python can find specify_cells

from specify_cells import CA1_Pyr

###  PARAMETERS 
# adapted from Mark Cembrowski in Bloss et al. (20156) found at https://modeldb.science/187610?tab=2&file=arrayTomography//mosinit.hoc

celsius = 35 # celcius, physiological temperature
v_init = -70 # mV, initial membrane potential
global_ra = 200.00 # ohm*cm, axial resistivity (internal resistivity)
Cm = 1.5  # uF/cm^2, membrane capacitance (specific membrane capacitance)
Rm = 40000  # uF/cm^2, membrane capacitance (passive membrane capacitance)
Vleak = -46  # mV, leak reversal potential
spinelimit = 100  # um, distance threshold where spines affect properties
spinefactor = 2.0  # scales capacitance and conductance past the spine limit

setgk = 0.036  # S/cm^2, base K conductance (kap and kad)
gkdr = 0.040  # S/cm^2, delayed rectifier K conductance (opens with a delay following membrane depolarization)
gkap = setgk  # proximal A-type K conductance
gkad = setgk  # distal A-type K conductance
dlimit = 300  # um, maximum distance for conductance gradient
dprox = 50  # um, proximal threshold for channel gradient
dslope = 0.01  # slope of conductance gradient with distance

gnaSoma = 0.1 # sodium conductance in the soma
gnaSlm = 0.03 # in tuft
gnaSr = 0.03 # in other dendrites

###  HELPER FUNCTIONS 
# adapted from Mark Cembrowski in Bloss et al. (20156) found at https://modeldb.science/187610?tab=2&file=arrayTomography//mosinit.hoc

def insert_soma_channels(cell):
    for node in cell.soma:
        sec = node.sec
        sec.insert('nax') # fast sodium channel
        sec.gbar_nax = gnaSoma # setting the max conductance for Na
        
        sec.insert('kdr') # delayed rectifier K channel
        sec.gkdrbar_kdr = gkdr # setting the max conductance for kdr
        
        sec.insert('kap') # A-type K channel (proximal)
        sec.gkabar_kap = gkap # setting the max conductance for kap
        
        sec.insert('kad') # A-type K channel (distal)
        sec.gkabar_kad = 0 # disabling the max conductance for kap
        
        sec.insert('pas') # passive leak conductance
        sec.e_pas = Vleak # leak reversal potential
        sec.g_pas = 1.0 / Rm # leak conductance (inverse of membrane resistance)
        sec.Ra = global_ra # axial resistance
        sec.cm = Cm # membrane conductance

def insert_basal_apical_channels(cell, seclist):
    for node in seclist:
        sec = node.sec
        sec.insert('pas') # passive leak conductance
        sec.e_pas = Vleak # leak reversal potential
        sec.Ra = global_ra # axial resistance
        # passive parameters adjusted by distance and spines 
        for seg in sec:
            dist_to_soma = h.distance(sec(seg.x)) # this is the distance from the soma to the origin
            if dist_to_soma <= spinelimit: # if we are within the spine limit distance
                seg.g_pas = 1.0 / Rm # set base leak conductance
                seg.cm = Cm # set base capacitance
            else: # we are beyond the spine limit 
                seg.g_pas = spinefactor / Rm # increased leak conductance
                seg.cm = spinefactor * Cm # increased capacitance
        # inserting the active channels
        sec.insert('nax')
        sec.insert('kdr')
        sec.gkdrbar_kdr = gkdr
        sec.insert('kap')
        sec.insert('kad')
        # distance dependent conductances for kap and kad
        for seg in sec:
            dist = min(h.distance(sec(seg.x)), dlimit)
            seg.gkabar_kap = 0
            seg.gkabar_kad = 0
            if dist > dprox:
                seg.gkabar_kad = gkad * (1 + dist * dslope)
            else:
                seg.gkabar_kap = gkap * (1 + dist * dslope)

def insert_tuft_channels(cell, seclist, gbar_value):
    for node in seclist:
        sec = node.sec
        sec.insert('nax')
        sec.gbar_nax = gbar_value

def finalize_soma(cell):
    # Set zero distance origin at soma middle (segment)
    h.distance(0, cell.soma[0].sec(0.5))  # pass the segment, no need to call .sec again
    
    for node in cell.soma:
        sec = node.sec
        sec.gbar_nax = gnaSoma

#  MAIN INITIALIZER 
def init_cell(v_init=-70, celsius=35):
    # Load the morphology
    cell = CA1_Pyr("EB1-early-bifurcation.swc") # Emily: use EB2-late-bifurcation.swc here

    # Set distance origin at soma
    h.distance(0, cell.soma[0].sec(0.5))

    # Insert channels
    insert_soma_channels(cell)
    insert_basal_apical_channels(cell, cell.basal)
    insert_basal_apical_channels(cell, cell.apical)
    insert_tuft_channels(cell, cell.tuft, gnaSlm)
    finalize_soma(cell)

    # Global simulation params
    h.v_init = v_init
    h.celsius = celsius
    h.dt = 0.1

    return cell

