#include "Engine.h"
#include <cmath>
#include <algorithm>

std::vector<double> generate_path(double S0, double r, double sigma, double T, int steps, std::mt19937 &gen)
{
    double dt = T / steps;
    std::vector<double> path;
    path.reserve(steps + 1); // allocate memory once to avoid re-allocations
    path.push_back(S0);

    double current_S = S0;

    std::normal_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < steps; ++i)
    {
        double Z = dist(gen);

        current_S = current_S * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        path.push_back(current_S);
    }

    return path;
}

double call_payoff(double S_T, double K)
{
    return std::max(S_T - K, 0.0);
}