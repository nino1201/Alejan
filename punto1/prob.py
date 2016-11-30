import corner
import numpy as np

files=np.genfromtxt('sismos.dat')

figure = corner.corner(files,labels=[r"$x$", r"$y$", r"$\Gamma \, [\mathrm{parsec}]$"],quantiles=[0.16, 0.5], show_titles=True ,title_kwargs={"fontsize": 12})

figure.savefig("sismos.pdf")
