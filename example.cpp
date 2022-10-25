#include <iostream>
#include "noise1d.hpp"

int main()
{
    // Create a 1D noise generator with a random seed
    noise1d::Noise1DGenerator n1d;

    // Get noise value at t = 10.f
    double noise = n1d.noise(10.f);
    std::cout << "Noise at t=10: " << noise << "\n";

    // Get seed
    uint seed = n1d.getSeed();
    std::cout << "Seed: " << seed << "\n";

    // You can also create a noise generator with a given seed
    noise1d::Noise1DGenerator n1d(12345678);

    return 0;
}