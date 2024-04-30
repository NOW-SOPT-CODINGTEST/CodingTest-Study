import heapq


def solution(jobs):
    tasks = len(jobs)
    res, time, start = 0, 0, -1
    H = []
    i = 0

    while i < tasks:
        for j in jobs:
            if start < j[0] <= time:
                heapq.heappush(H, (j[1], j[0]))

        if H:
            work, reqTime = heapq.heappop(H)
            start = time
            time += work
            res += time - reqTime
            i += 1
        else:
            time += 1

    return res // tasks
