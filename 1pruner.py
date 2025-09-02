import random
from neuron import h

v_init = -67  # baseline membrane potential


def safe_delete_section(sec):
    
    # safely delete section from NEURON
    
    try:
        h.pop_section() # NEURON built in function
    except Exception:
        pass
    try:
        h.delete_section(sec=sec) # NEURON built in function
        return True
    except Exception as e:
        print(f"Failed to delete section {sec.name()}: {e}")
        return False


def delete_fraction_of_spines_per_branch(cell, fraction=0.25):
    
    # deletes a fraction of spines for every branch in the cell, a way to globally reduce spine density
    
    for sec_node in cell.apical + cell.basal + cell.tuft + cell.trunk:
        total_spines = len(sec_node.spines)
        if total_spines == 0:
            continue
        
        n_delete = max(1, int(total_spines * fraction)) # let's always delete 1, int rounds down
        to_delete = random.sample(sec_node.spines, n_delete) #random.sample chooses without replacement = choosing n_delete distinct spines
        
        for spine in to_delete:
            for part_name in ['head', 'neck']:
                part = getattr(spine, part_name, None)
                if part is not None:
                    sec_obj = getattr(part, 'sec', None)
                    if sec_obj is not None:
                        safe_delete_section(sec_obj)
        
        # remove pruned spines from the list, good
        for spine in to_delete:
            if spine in sec_node.spines:
                sec_node.spines.remove(spine)


def get_spines_by_branch(cell):
    
    # returns a dictionary mapping branch_name to a list of spines
    
    branch_spines = {}
    for sec_node in cell.apical + cell.basal + cell.tuft + cell.trunk:
        branch_name = sec_node.sec.name()
        spines = [s for s in sec_node.spines if 'spine_head' in s.name]
        branch_spines[branch_name] = spines
    return branch_spines


def find_matching_wt_spines(wt_cell, saa_spines, branch_name):
    
    # for each SAA spine, find the WT spine on the same branch

    # Find the WT branch
    wt_sec_node = None
    for sec_node in wt_cell.apical + wt_cell.basal + wt_cell.tuft + wt_cell.trunk:
        if sec_node.sec.name() == branch_name:
            wt_sec_node = sec_node
            break
    if wt_sec_node is None:
        raise Exception(f"WT branch {branch_name} not found")
    
    matching_wt_spines = []
    for saa_spine in saa_spines:
        saa_loc_norm = getattr(saa_spine, 'loc', None)
        if saa_loc_norm is None:
            continue
        
        # finding the WT spine with the same location
        for wt_spine in getattr(wt_sec_node, 'spines', []):
            wt_loc_norm = getattr(wt_spine, 'loc', None)
            if wt_loc_norm is None:
                continue
            if wt_loc_norm == saa_loc_norm:
                matching_wt_spines.append(wt_spine)
                break  # stop after finding the match
    
    return matching_wt_spines


def delete_fraction_from_branch_in_one_third(branch, target_third, fraction):
    total_spines = len(branch.spines)
    print(f"Branch {branch.sec.name()} has {total_spines} spines total.")

    if total_spines < 3:
        print("Not enough spines!")
        return

    # defining index bounds for each third
    third = total_spines // 3
    bounds = [
        (0, third),   # first          
        (third, 2 * third),     # second
        (2 * third, total_spines) # third
    ]

    start_id, end_id = bounds[target_third - 1] # the start and end index for each third
    spines_in_section = branch.spines[start_id:end_id] # getting all the spines in that third
    print(f"Third {target_third} has indices {start_id} to {end_id}, a total {len(spines_in_section)} spines")


    n_delete = max(1, int(len(spines_in_section) * fraction)) # always round down and always one spine will be deleted
    print(f"Deleting {n_delete} spines out of {len(spines_in_section)} in this section.")


    to_delete = random.sample(spines_in_section, min(n_delete, len(spines_in_section))) # random sample to delete!!

    for spine in to_delete:
        spine_id = branch.spines.index(spine)
        print(f"Deleting spine at index {spine_id}")
        for part_name in ['head', 'neck']:
            part = getattr(spine, part_name, None) # get head/neck
            if part is not None:
                sec_obj = getattr(part, 'sec', None) # get NEURON segment
                if sec_obj is not None:
                    print(f"\tDeleting {part_name} section")
                    safe_delete_section(sec_obj)
        if spine in branch.spines:
            branch.spines.remove(spine) # remove from list
    print("Deletion from this branch third done.\n")

# Globals for synapses
synapses = []
stims = []
netcons = []
