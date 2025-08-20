# Suppose you have a list of your favorite apical branches as `favorite_branches`
favorite_branches = [cell.apical[i] for i in [3, 7, 12]]  # example indices of favorites

# Pick one branch (e.g., the first favorite)
sec_node = favorite_branches[0]  
sec = sec_node.sec
branch_name = sec.name()

print(f"Selected terminal apical branch: {branch_name} with {len(sec_node.spines)} spines")

import matplotlib.pyplot as plt
plt.figure(figsize=(10,6))

spine_counts_to_test = [5, 10]

for n_spines in spine_counts_to_test:
    t, v_soma, v_dend, spikes, spines = simulate_and_record(sec_node, n_spines)
    print(f"{n_spines} spines stimulated - dendritic spikes: {spikes}")
    plt.plot(t, v_dend, label=f'{n_spines} spines')

plt.axvline(100, linestyle='--', color='orange', label='Stimulation time')
plt.xlabel("Time (ms)")
plt.ylabel("Membrane Potential (mV)")
plt.title(f"Stimulating {branch_name} terminal apical branch")
plt.legend()
plt.tight_layout()
plt.show()
