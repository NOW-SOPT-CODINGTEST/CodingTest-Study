from collections import deque


def solution(elements):
    res = set()
    for i in range(1, len(elements) + 1):
        Q = deque(maxlen=i)
        for j in elements * 2:
            Q.append(j)
            res.add(sum(Q))
    return len(res)
