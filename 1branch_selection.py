#branch_selection.py

from neuron import h
from spine_analysis import count_spines, region_density

def list_sections(cell):
    
    # returns all section nodes (not just names)
    
    return cell.basal + cell.apical + cell.tuft + cell.trunk


def filter_by_length(cell, min_length=0, max_length=None, region=None):

    # returns sections based on their physical length.
    # for region: can be 'basal', 'apical', 'tuft', 'trunk', or None (all).

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        if sec.L >= min_length and (max_length is None or sec.L <= max_length):
            results.append(sec)
    return results


def filter_by_spine_count(cell, min_spines=0, region=None):

    # returns sections with at least `min_spines` attached spines.

    sec_stats = count_spines(cell)  # get per-section stats

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        stats = sec_stats.get(sec.name(), {})
        total_spines = stats.get("necks", 0) + stats.get("heads", 0) # for sanity check
        if total_spines >= min_spines:
            results.append(sec)
    return results


def filter_by_density(cell, min_density=0, region=None):

    # returns sections with spine density above min_density (spines/µm).

    sec_stats = count_spines(cell)

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        stats = sec_stats.get(sec.name(), {})
        total_spines = stats.get("necks", 0) + stats.get("heads", 0)
        density = total_spines / sec.L if sec.L > 0 else 0
        if density >= min_density:
            results.append(sec)
    return results


def filter_by_distance(cell, min_dist=0, max_dist=None, region="apical", soma=None):

    # returns sections based on distance from the soma.
    # returns a list of (section, distance) tuples.
    
    """
    INPUTS
    - min_dist: minimum distance,  µm
    - max_dist: maximum distance, µm (for no upper limit = None)
    - region: which section list to use (apical, basal, ...)
    - soma: reference soma section (default: first soma)
    """
    if soma is None:
        soma = cell.soma[0]

    # set reference point at middle of soma
    h.distance(0, soma.sec(0.5))

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        dist = h.distance(sec(0.5))
        if dist >= min_dist and (max_dist is None or dist <= max_dist):
            results.append((sec, dist))  # store both
    return results

def find_branch_by_name(cell, target_suffix):
    
    # returns the branch whose node name ends with the target_suffix (ie: apical131)
    
    for sec_node in list_sections(cell):
        if sec_node.sec.name().endswith(target_suffix):
            return sec_node
    return None

def get_terminal_dendritic_sections(cell):

    # returns branches with no children

    all_secs = list_sections(cell)

    # spines are considered separate; exclude them
    dend_secs = [sec_node.sec for sec_node in all_secs if not any(x in sec_node.sec.name() for x in ['spine_', 'Spine'])]

    # build parent -> children map
    parent_map = {sec: [] for sec in dend_secs}
    child_set = set()

    for sec in dend_secs:
        for child in sec.children():
            if child in dend_secs:
                parent_map[sec].append(child)
                child_set.add(child)

    # terminal sections have no children
    terminal_secs = [sec for sec in dend_secs if len(parent_map[sec]) == 0]

    return terminal_secs
