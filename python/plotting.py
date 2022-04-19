from numpy import arange
from matplotlib import pyplot as plt
from math import sin

def plot():

    fig, ax = plt.subplots()

    plt.plot(x, y)
    plt.xticks(x)
    plt.yticks([i for i in range(-15000, 15000, 1000)])
    fig.suptitle("Mass Haul Diagram",
                fontsize=30, fontweight='bold', **title_font)
    ax.grid()
    plt.ylim([-15000, 15000])
    plt.xlabel("Distance From Station 0 (m)",
                fontsize=med_fontsize, fontweight="bold")
    plt.ylabel("Mass Ordinates (m^3)",
                fontsize=med_fontsize, fontweight="bold")
    plt.axhline(y=0, color='k', linestyle='dashed')

    # Make a plot with major ticks that are multiples of 20 and minor ticks that
    # are multiples of 5.  Label major ticks with '.0f' formatting but don't label
    # minor ticks.  The string is used directly, the `StrMethodFormatter` is
    # created automatically.
    ax.yaxis.set_major_locator(MultipleLocator(2000))
    ax.yaxis.set_major_formatter('{x:.0f}')

    # For the minor ticks, use no labels; default NullFormatter.
    ax.yaxis.set_minor_locator(MultipleLocator(500))

    plt.show()

if __name__ == "__main__":
    x = [n for n in arange(-10, 10, 0.1)]
    y = [pow(n, 2) for n in x]

    plot(x, y, "x", "y", "idk man",
         20, "light", )
