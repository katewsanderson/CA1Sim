from neuron import h
import numpy as np

v_init = -67  # resting potential

# Global containers
synapses = []
stims = []
netcons = []


def simulate_and_record(cell, sec_node, spines_to_stim, delay=100, weight=0.0018, threshold=-25):
   global synapses, stims, netcons
   synapses.clear()
   stims.clear()
   netcons.clear()


   for spine in spines_to_stim:
       # synapse on the spine head
       syn = h.Exp2Syn(spine.sec(0.5))
       syn.tau1 = 0.2 # rise time
       syn.tau2 = 2.0 # decay time
       syn.e = 0 # reversal potential

        # connect the spike generator to the synapse
       stim = h.NetStim()
       stim.number = 1 # just one spike
       stim.start = delay # spike will occur @ 100ms

        # connect the spike generator to the synapse
       nc = h.NetCon(stim, syn)
       nc.weight[0] = weight # synaptic weight (conductance in uS)

       synapses.append(syn)
       stims.append(stim)
       netcons.append(nc)


   t = h.Vector().record(h._ref_t)
   v_soma = h.Vector().record(cell.soma[0].sec(0.5)._ref_v) # soma
   v_dend = h.Vector().record(sec_node.sec(0.5)._ref_v) # dendritic shaft


   h.finitialize(v_init)
   h.continuerun(200)


   t_np = np.array(t)
   v_soma_np = np.array(v_soma)
   v_dend_np = np.array(v_dend)


   spike_times = detect_spike_times(v_dend_np, t_np, threshold)
   spike_count = len(spike_times)

   print(f"Spike count detected on {sec_node.sec.name()}: {spike_count}")

   return t_np, v_soma_np, v_dend_np, spike_count

def detect_spike_times(v, t, threshold = -25):
    spike_times = []
    above = v > threshold
    for i in range(1, len(v)):
        if above[i] and not above[i-1]:
            spike_times.append(t[i])
    return spike_times

def get_peak_voltage(trace):
   return max(trace) - trace[0]