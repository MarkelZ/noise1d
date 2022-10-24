from math import sin, cos
import random as rnd


class Noise1DGenerator:
    C1 = 1.772453850905516104
    C2 = 1.648721270700128194
    DEFAULT_COEFMAX = 65536

    def __init__(self, seed=None, coefMax=DEFAULT_COEFMAX):
        self._seed = seed
        rnd.seed(seed)
        self.coefs = [rnd.randint(1, coefMax) for _ in range(4)]

    def noise(self, t):
        return (sin(t + self.coefs[0]) * cos(Noise1DGenerator.C1*t + self.coefs[1]) +
                sin(2*t + self.coefs[2]) * cos(Noise1DGenerator.C2*t + self.coefs[3])) / 2.0

    def get_seed(self):
        self._seed
