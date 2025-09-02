# plaque.py
import random
from pruner  import safe_delete_section  
def plaque_prune(branch, target_third, fraction=0.5, rng=None):
    """
    Delete a fraction of spines from a specific third of a branch.
    """
    if rng is None:
        rng = random

    total_spines = len(branch.spines)
    if total_spines < 3:
        print(f"Branch {branch.sec.name()} has too few spines for thirds.")
        return []

    # Bounds for thirds
    third = total_spines // 3
    bounds = [
        (0, third),
        (third, 2 * third),
        (2 * third, total_spines),
    ]

    start_id, end_id = bounds[target_third - 1]
    spines_in_section = branch.spines[start_id:end_id]

    if not spines_in_section:
        print(f"No spines found in third {target_third} of {branch.sec.name()}")
        return []

    n_delete = max(1, int(len(spines_in_section) * fraction))
    to_delete = rng.sample(spines_in_section, min(n_delete, len(spines_in_section)))

    deleted = []
    for spine in to_delete:
        for part_name in ['head', 'neck']:
            part = getattr(spine, part_name, None)
            if part is not None and hasattr(part, 'sec'):
                safe_delete_section(part.sec)
        if spine in branch.spines:
            branch.spines.remove(spine)
            deleted.append(spine)

    return deleted
