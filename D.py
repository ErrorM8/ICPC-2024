import math

def expected_weight(N, red_weights, green_weights):
    results = []  # Store the expected weights for each K
    for K in range(1, N + 1):
        total_