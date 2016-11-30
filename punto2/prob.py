import corner
import numpy as np

files=np.genfromtxt('planetas.dat')

figure = corner.corner(files,labels=[r"$n$", r"$log(M)$", r"$\Gamma \, [\mathrm{parsec}]$"],quantiles=[0.16, 0.5],show_titles=True, title_kwargs={"fontsize": 12})

figure.savefig("planetas.png")
