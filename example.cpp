#include <iostream>
#include "noise1d.hpp"

int main()
{
    // Construct a 1D noise generator with seed 123
    uint seed = 123;
    noise1d::Noise1DGenerator n1d(seed);

    // Get noise value at t = 10.f
    std::cout << n1d.noise(10.f) << "\n";

    return 0;
}