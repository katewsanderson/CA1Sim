import matplotlib.pyplot as plt

def plot_traces(wt_results, saa_results):
    """Plot WT vs SAA results at soma and dendrite."""
    colors = ['tab:blue', 'tab:orange', 'tab:green']
    linestyle_wt, linestyle_saa = '-', '--'
    fig, axs = plt.subplots(2, 1, figsize=(10, 8), sharex=True)

    for i, (wt, saa) in enumerate(zip(wt_results, saa_results)):
        color = colors[i % len(colors)]
        label = f"(loc={wt['location']:.1f})"

        axs[0].plot(wt['t'], wt['soma_v'], color=color, linestyle=linestyle_wt, label=f"WT {label}")
        axs[0].plot(saa['t'], saa['soma_v'], color=color, linestyle=linestyle_saa, label=f"SAA {label}")
        axs[1].plot(wt['t'], wt['dend_v'], color=color, linestyle=linestyle_wt, label=f"WT {label}")
        axs[1].plot(saa['t'], saa['dend_v'], color=color, linestyle=linestyle_saa, label=f"SAA {label}")

    axs[0].set_title("Soma Voltage Traces")
    axs[1].set_title("Dendrite Voltage Traces")
    axs[1].set_xlabel("Time (ms)")
    axs[0].set_ylabel("Membrane Potential (mV)")
    axs[1].set_ylabel("Membrane Potential (mV)")
    axs[0].legend(fontsize='small')
    axs[1].legend(fontsize='small')
    plt.tight_layout()
    plt.show()
