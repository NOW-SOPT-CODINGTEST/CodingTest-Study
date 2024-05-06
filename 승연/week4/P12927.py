import heapq


def solution(n, works):
    H = []
    res = 0
    for i in works:
        heapq.heappush(H, i * -1)
    while n > 0:
        longest = heapq.heappop(H)
        longest += 1
        heapq.heappush(H, longest)
        n -= 1
    if min(H) >= 0:
        return 0
    for i in H:
        res += (-1 * i) ** 2
    return res
