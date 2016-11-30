import corner
import numpy as np

files=np.genfromtxt('biologos.dat')

figure = corner.corner(files,labels=[r"$\alpha$", r"$\beta$",r"$\gamma$",r"$\delta$", r"$\Gamma \, [\mathrm{parsec}]$"],quantiles=[0.16, 0.5,0.16,0.15], show_titles=True, title_kwargs={"fontsize": 12})

figure.savefig("biologos.pdf")
