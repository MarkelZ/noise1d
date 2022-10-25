#pragma once
#include <cmath>
#include <ctime>

namespace noise1d
{
    /**
     *
     * One-dimensional noise with spatial consistency.
     *
     * > Ranges from -1 to 1, including both endpoints.
     * > It is smooth, and aperiodic.
     *
     * Note that this is not perlin/simplex noise.
     */
    class Noise1DGenerator
    {
    private:
        // Mutually irrational constants
        static constexpr double C1 = 1.772453850905516104;
        static constexpr double C2 = 1.648721270700128194;

        // Default maximum value of coeficients
        static constexpr uint DEFAULT_COEFMAX = 65536;

        // Seed of the rng used for generating the coefficients
        const uint seed;

        // Coefficients for generating the noise
        double coefs[4];

    public:
        /**
         * @brief Construct a new Noise1DGenerator object
         *
         * @param seed Seed of the random number generator.
         * @param coefMax Maximum value a coeficient can have.
         */
        Noise1DGenerator(uint seed = static_cast<uint>(std::time(nullptr)), uint coefMax = DEFAULT_COEFMAX)
            : seed(seed)
        {
            srand(seed);
            for (int i = 0; i < 4; i++)
                coefs[i] = 1 + (rand() % coefMax);
        }

        /**
         * @brief Return the value of the noise at t.
         *
         * @param t Input value ranging from -infinity to infinity.
         * @return Value of the noise ranging from -1 to 1.
         */
        inline double noise(double t)
        {
            return (sin(t + coefs[0]) * cos(C1 * t + coefs[1]) +
                    sin(2 * t + coefs[2]) * cos(C2 * t + coefs[3])) /
                   2.0;
        }

        /**
         * @brief Return the seed used to generate the coefficients of this generator.
         */
        inline uint getSeed()
        {
            return seed;
        }
    };
}