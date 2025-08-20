from neuron import h

# ----------------------------
# Dendritic Section Utilities
# ----------------------------

def all_dendritic_sections(print_on=False):
    """Return all dendritic sections (basal, apical, tuft)."""
    all_dends = [sec for sec in h.allsec() if 'dend' in sec.name() or 'apic' in sec.name() or 'tuft' in sec.name()]
    if print_on:
        print(f"Found {len(all_dends)} dendritic sections")
    return all_dends


def count_spines_per_section(cell, print_on=False):
    """Return a dict mapping dendritic section -> number of spines."""
    all_dends = all_dendritic_sections()
    spines = [s for s in h.allsec() if 'spine_neck' in s.name()]

    spine_counts = {}
    for sec in all_dends:
        count = 0
        for head in spines:
            parent_seg = head.parentseg()
            if parent_seg is not None and parent_seg.sec.name() == sec.name():
                count += 1
        spine_counts[sec.name()] = count
        if print_on:
            print(f"{sec.name():<30} | Length: {sec.L:6.2f} µm | Spines: {count}")

    return spine_counts


def get_terminal_dendritic_sections(print_on=False):
    """Return terminal dendritic sections (no children, excluding spines)."""
    all_secs = [sec for sec in h.allsec() if not any(x in sec.name() for x in ['spine_', 'Spine'])]
    parent_map = {sec: [] for sec in all_secs}

    for sec in all_secs:
        for child in sec.children():
            if child in all_secs:
                parent_map[sec].append(child)

    terminal_secs = [sec for sec in all_secs if len(parent_map[sec]) == 0]
    if print_on:
        print(f"Found {len(terminal_secs)} terminal dendritic sections")
    return terminal_secs


def filter_terminal_by_name_keyword(terminal_secs, keyword="apical", print_on=False):
    """Filter terminal sections by keyword in their name."""
    filtered = [sec for sec in terminal_secs if keyword in sec.name()]
    if print_on:
        print(f"{len(filtered)} terminal sections with keyword '{keyword}'")
    return filtered


def get_terminal_apical_with_spines(cell, terminal_apical_secs, min_spines=20, print_on=False):
    """Return terminal apical dendrites with at least `min_spines`."""
    sec_node_map = {sn.sec: sn for sn in cell.apical}
    filtered = []

    for sec in terminal_apical_secs:
        if sec in sec_node_map:
            sn = sec_node_map[sec]
            n_spines = len(getattr(sn, 'spines', []))
            if n_spines >= min_spines:
                density = n_spines / sec.L if sec.L > 0 else 0
                filtered.append((sec, sn, n_spines, density))

    if print_on:
        print(f"Filtered to {len(filtered)} terminal apical dendrites with ≥ {min_spines} spines")
    return filtered


def find_two_apical_branches_distal_less_dense(cell, terminal_apical_secs, density_tolerance=0.1, print_on=False):
    """Find two apical terminal branches where the distal one is less dense than proximal."""
    h.distance(0, cell.soma[0].sec(0.5))
    branch_info = []
    sec_node_map = {sn.sec: sn for sn in cell.apical}

    for sec in terminal_apical_secs:
        if sec in sec_node_map:
            sn = sec_node_map[sec]
            n_spines = len(getattr(sn, 'spines', []))
            length = sec.L if sec.L > 0 else 1
            density = n_spines / length
            dist = h.distance(sec(0.5))
            branch_info.append((sec, dist, n_spines, length, density))

    branch_info.sort(key=lambda x: x[1])
    best_pair = None
    max_dist_diff = -1

    for i in range(len(branch_info)):
        for j in range(i+1, len(branch_info)):
            prox = branch_info[i]
            dist = branch_info[j]
            density_diff = abs(prox[4] - dist[4]) / max(prox[4], dist[4])
            dist_diff = dist[1] - prox[1]

            if density_diff <= density_tolerance and dist[4] < prox[4]:
                if dist_diff > max_dist_diff:
                    max_dist_diff = dist_diff
                    best_pair = (prox, dist)

    if best_pair is None:
        if print_on:
            print("No branch pair found meeting criteria")
        return None

    if print_on:
        (sec1, d1, nsp1, l1, dens1), (sec2, d2, nsp2, l2, dens2) = best_pair
        print(f"Proximal Branch: {sec1.name()} | Distance: {d1:.1f} µm | Spines: {nsp1} | Length: {l1:.1f} µm | Density: {dens1:.3f}")
        print(f"Distal Branch:   {sec2.name()} | Distance: {d2:.1f} µm | Spines: {nsp2} | Length: {l2:.1f} µm | Density: {dens2:.3f}")
        print(f"Distance diff: {d2 - d1:.1f} µm | Density diff: {dens1 - dens2:.3f}")

    return best_pair
