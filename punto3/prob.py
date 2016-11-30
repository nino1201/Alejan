import corner
import numpy as np

files=np.genfromtxt('biologos.dat')

figure = corner.corner(files, title_kwargs={"fontsize": 12})

figure.savefig("biologos.png")
