import random

random.seed(786872638476234)

T = 85

print T
for cs in range(T):
    N, M = [random.randint(2, 1000000) for _ in range(2)]
    K = random.randint(2, min(N, M))
    S = random.randint(1, 1000000000)
    DP = random.randint(1, 500000000)
    DQ = random.randint(1, 500000000)
    print N, M, K, S
    for _ in range(K):
        print random.randint(1, DP),
    print
    for _ in range(3):
        print random.randint(0, 1000000000),
    print DP
    for _ in range(K):
        print random.randint(1, DQ),
    print
    for _ in range(3):
        print random.randint(0, 1000000000),
    print DQ
