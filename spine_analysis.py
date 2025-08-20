from neuron import h

def count_spines(cell):
    """Return a dict of spine counts (necks and heads) per section."""
    spine_necks = [s for s in h.allsec() if 'spine_neck' in s.name()]
    spine_heads = [s for s in h.allsec() if 'spine_head' in s.name()]

    results = {}

    for sec_node in cell.basal + cell.apical + cell.tuft + cell.trunk:
        sec = sec_node.sec
        neck_count = 0
        head_count = 0

        # count necks
        for neck in spine_necks:
            parent_seg = neck.parentseg()
            if parent_seg is not None and parent_seg.sec.name() == sec.name():
                neck_count += 1

        # count heads
        for head in spine_heads:
            neck_seg = head.parentseg()
            if neck_seg is None:
                continue
            dend_seg = neck_seg.sec.parentseg()
            if dend_seg is not None and dend_seg.sec.name() == sec.name():
                head_count += 1

        results[sec.name()] = {
            "length": sec.L,
            "necks": neck_count,
            "heads": head_count
        }

    return results


def region_density(cell):
    """Return summary spine densities per region."""
    regions = {
        "basal": cell.basal,
        "trunk": cell.trunk,
        "apical": cell.apical,
        "tuft": cell.tuft
    }

    stats = {}
    for region_name, sec_list in regions.items():
        total_spines = 0
        total_length = 0.0

        for sec_node in sec_list:
            sec = sec_node.sec
            total_length += sec.L
            if hasattr(sec_node, 'spines'):
                total_spines += len(sec_node.spines)

        spine_density = total_spines / total_length if total_length > 0 else 0
        stats[region_name] = {
            "spines": total_spines,
            "length (µm)": total_length,
            "spines/µm": spine_density
        }

    return stats


def print_summary(stats):
    """Pretty-print region density stats."""
    for region, values in stats.items():
        print(f"{region.capitalize():<8} | "
              f"Spines: {values['spines']:>4} | "
              f"Length: {values['length (µm)']:.1f} µm | "
              f"Density: {values['spines/µm']:.3f} spines/µm")