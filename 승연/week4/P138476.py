from collections import Counter


def solution(k, tangerine):
    res = 0
    cnt = 0
    for i in Counter(tangerine).most_common():
        cnt += i[1]
        res += 1
        if cnt >= k:
            return res
