prime_factors = []

n = 20
k = 10

composite = [True] * 2 + [False] * n

for p in xrange(n + 1):
    if composite[p]:
        continue

    q = p
    m = 1
    total_prime_power = 0
    prime_power = [0] * (n + 1)

    while True:

        prime_power[q] = prime_power[m] + 1
        r = q

        if q <= k:
            total_prime_power -= prime_power[q]

        if q > n - k:
            total_prime_power += prime_power[q]

        m += 1
        q += p

        if q > n:
            break

        composite[q] = True

    prime_factors.append([p, total_prime_power])

print prime_factors
