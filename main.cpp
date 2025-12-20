#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    double S0 = 100.0;
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    int N = 100000;

    // rng
    std::random_device rd;

    std::mt19937 generator(rd());

    std::normal_distribution<double> distribution(0.0, 1.0);

    double sum_payoffs = 0.0;

    for (int i = 0; i < N; ++i)
    {
        double Z = distribution(generator);

        double S_T = S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * Z);

        double payoff = std::max(S_T - K, 0.0);

        sum_payoffs += payoff;
    }

    double average_payoff = sum_payoffs / N;
    double option_price = exp(-r * T) * average_payoff;

    cout << "Number of Paths: " << N << endl;
    cout << "Underlying:      " << S0 << endl;
    cout << "Strike:          " << K << endl;
    cout << "Option Price:    " << option_price << endl;

    return 0;
}