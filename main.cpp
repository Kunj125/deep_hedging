#include <iostream>
#include <random>
#include <vector>
#include "Engine.h"

using namespace std;

int main()
{
    double S0 = 100.0;
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    int steps = 100;
    int N = 100000;

    // rng
    random_device rd;
    mt19937 generator(rd());
    normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < 5; ++i)
    {
        vector<double> path = generate_path(S0, r, sigma, T, steps, generator);

        cout << "Path " << i + 1 << " Final Price: " << path.back() << endl;
    }

    return 0;
}