#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <random>

std::vector<double> generate_path(double S0, double r, double sigma, double T, int steps, std::mt19937 &gen);

double call_payoff(double S_T, double K);

#endif