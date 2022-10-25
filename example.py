import noise1d
import matplotlib.pyplot as plt
import numpy as np

# Create a 1D noise generator with a random seed
n1d = noise1d.Noise1DGenerator()

# Get noise value at t = 10.f
noise = n1d.noise(10.0)
print('Noise at t=10: ', noise)

# Get seed
seed = n1d.get_seed()
print('Seed: ', seed)

# You can also create a noise generator with a given seed
n1d = noise1d.Noise1DGenerator(seed=12345678)

# Plot the curve for t in [0, 20]
tt = np.linspace(start=0.0, stop=20.0, num=256)
yy = [n1d.noise(t) for t in tt]
plt.plot(tt, yy)
plt.show()
