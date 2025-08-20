from neuron import h
from spine_analysis import count_spines, region_density

def list_sections(cell):
    """Return all section nodes (not just names)."""
    return cell.basal + cell.apical + cell.tuft + cell.trunk


def filter_by_length(cell, min_length=0, max_length=None, region=None):
    """
    Select sections based on their physical length.
    region: restrict search to 'basal', 'apical', 'tuft', 'trunk', or None (all).
    """
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
    """
    Select sections with at least `min_spines` attached spines.
    """
    sec_stats = count_spines(cell)  # get per-section stats

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        stats = sec_stats.get(sec.name(), {})
        total_spines = stats.get("necks", 0) + stats.get("heads", 0)
        if total_spines >= min_spines:
            results.append(sec)
    return results


def filter_by_density(cell, min_density=0, region=None):
    """
    Select sections with spine density above min_density (spines/µm).
    """
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
    """
    Select sections based on distance from the soma.
    - min_dist: minimum distance in µm
    - max_dist: maximum distance in µm (None for no upper limit)
    - region: which section list to use ('apical', 'basal', etc.)
    - soma: reference soma section (default: first soma)
    """
    if soma is None:
        soma = cell.soma[0]

    # Set reference point at middle of soma
    h.distance(0, cell.soma[0].sec(0.5))

    if region:
        sec_list = getattr(cell, region)
    else:
        sec_list = list_sections(cell)

    results = []
    for sec_node in sec_list:
        sec = sec_node.sec
        dist = h.distance(sec(0.5))
        if dist >= min_dist and (max_dist is None or dist <= max_dist):
            results.append(sec)
    return results
