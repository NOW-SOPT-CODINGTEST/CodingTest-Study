import itertools
from collections import Counter


def solution(tickets):
    res = []
    tick = list(itertools.chain(*tickets))
    dict = {i: [] for i in tick}
    for i in tickets:
        dict[i[0]].append(i[1])
    for i in dict:
        dict[i].sort()

    arr = tickets[:]

    def dfs(x):
        res.append(x)
        for i in dict[x]:
            if [x, i] in arr:
                arr.remove([x, i])
                dfs(i)

    dfs("ICN")
    return res


# 테케 1,2 번 틀림
