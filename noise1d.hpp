#pragma once
#include <cmath>
#include <ctime>

namespace noise1d
{
    class Noise1DGenerator
    {
    private:
        static constexpr double C1 = 1.772453850905516104;
        static constexpr double C2 = 1.648721270700128194;
        static constexpr uint DEFAULT_COEFMAX = 65536;

        const uint seed;
        double coefs[4];

    public:
        Noise1DGenerator(uint seed = static_cast<uint>(std::time(nullptr)), uint coefMax = DEFAULT_COEFMAX)
            : seed(seed)
        {
            srand(seed);
            for (int i = 0; i < 4; i++)
                coefs[i] = 1 + (rand() % coefMax);
        }

        inline double noise(double t)
        {
            return (sin(t + coefs[0]) * cos(C1 * t + coefs[1]) +
                    sin(2 * t + coefs[2]) * cos(C2 * t + coefs[3])) /
                   2.0;
        }

        inline uint getSeed()
        {
            return seed;
        }
    };
}