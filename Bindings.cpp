#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Engine.h"
#include <random>

namespace py = pybind11;

std::vector<double> py_generate_path(double S0, double r, double sigma, double T, int steps) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    return generate_path(S0, r, sigma, T, steps, gen);
}

PYBIND11_MODULE(market_engine, m) {
    m.doc() = "Financial monte carlo engine in C++";
    
    // m.def("python_name", &cpp_function, "description");
    m.def("generate_path", &py_generate_path, "Generates a GBM price path");
    m.def("call_payoff", &call_payoff, "Calculates option payoff");
}