#pragma once
#include <cmath>

namespace noise1d
{
    class Noise1DGenerator
    {
    public:
        Noise1DGenerator(unsigned int seed = 0)
        {
            this->seed = seed;
        }

    private:
        unsigned int seed;
    };
}