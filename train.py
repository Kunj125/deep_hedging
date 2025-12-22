import torch
import torch.optim as optim
import numpy as np
from DeepHedging import HedgingNetwork
import market_engine

S0 = 100.0
K = 100.0
R = 0.05
SIGMA = 0.2
T = 1.0
STEPS = 50

BATCH_SIZE = 32
EPOCHS = 100
RISK_AVERSION = 1.0

def train():
    model = HedgingNetwork()
    learning_rate = 0.001
    optimizer = optim.Adam(model.parameters(), lr=learning_rate)
    
    for i in range(EPOCHS):
        paths = []
        for i in range(BATCH_SIZE):
            res = market_engine.generate_path(S0, R, SIGMA, T, STEPS)
            paths.append(res)
        price_paths = torch.tensor(paths, dtype=torch.float32)

        cash = torch.zeros(BATCH_SIZE)
        holdings = torch.zeros(BATCH_SIZE)
        dt = T / STEPS
        for t in range(STEPS):
            cur_prices = price_paths[:, t]
            time_left = T - (t * dt)



