def solution(cap, n, deliveries, pickups):
    deliveries = deliveries[::-1]
    pickups = pickups[::-1]
    res, pick, deliver = 0, 0, 0

    for i in range(n):
        pick += pickups[i]
        deliver += deliveries[i]

        while pick > 0 or deliver > 0:
            pick -= cap
            deliver -= cap
            res += (n - i) * 2
    return res
