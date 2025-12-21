import market_engine
import matplotlib.pyplot as plt
import time
import numpy as np

S0 = 100.0
r = 0.05
sigma = 0.2
T = 1.0
steps = 252 
num_paths = 50

print(f"Running {num_paths} simulations via C++ Engine...")

start = time.time()
paths = []
for i in range(num_paths):
    # this line calls the compiled C++ code
    path = market_engine.generate_path(S0, r, sigma, T, steps)
    paths.append(path)
end = time.time()

print(f"Done! Calculation took {end - start:.5f} seconds.")

plt.figure(figsize=(12, 6))
for p in paths:
    plt.plot(p, alpha=0.5, linewidth=0.8)

plt.title(f"Monte Carlo Simulation: {num_paths} Asset Paths (Generated in C++)")
plt.xlabel("Trading Days")
plt.ylabel("Asset Price")
plt.axhline(y=S0, color='black', linestyle='--', label="Start Price")
plt.grid(True, alpha=0.3)
plt.show()