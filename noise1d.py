from math import sin, cos
import random as rnd
from datetime import datetime


class Noise1DGenerator:
    """
    One-dimensional noise with spatial consistency. 

    - Ranges from -1 to 1, including both endpoints.
    - It is smooth, and aperiodic.

    Note that this is not perlin/simplex noise.
    """

    # Mutually irrational constants
    C1 = 1.772453850905516104
    C2 = 1.648721270700128194

    # Default maximum value of coeficients
    DEFAULT_COEFMAX = 65536

    def __init__(self, seed=None, coefMax=DEFAULT_COEFMAX):
        """
        Parameters
        ----------
        seed : int, optional
            Seed for the random number generator.

        coefMax : int, optional
            Maximum value a coeficient can have.
        """

        self._seed = datetime.now() if seed == None else seed
        rnd.seed(self._seed)

        self.coefs = [rnd.randint(1, coefMax) for _ in range(4)]

    def noise(self, t):
        """
        Return the value of the noise at t.

        t is a float that ranges from -infinity to infinity.

        The returned value ranges from -1 to 1.
        """

        return (sin(t + self.coefs[0]) * cos(Noise1DGenerator.C1*t + self.coefs[1]) +
                sin(2*t + self.coefs[2]) * cos(Noise1DGenerator.C2*t + self.coefs[3])) / 2.0

    def get_seed(self):
        """
        Return the seed used to generate the coefficients of this generator.
        """
        self._seed
