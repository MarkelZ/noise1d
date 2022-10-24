import noise1d

# Create a 1D noise generator with a random seed
n1d = noise1d.Noise1DGenerator()

# Get noise value at t = 10.f
noise = n1d.noise(10.0)
print('Noise at t=10: ', noise)

# Get seed
seed = n1d.get_seed()
print('Seed: ', seed)

# You can also create a noise generator with a given seed
n1d = noise1d.Noise1DGenerator(123)
