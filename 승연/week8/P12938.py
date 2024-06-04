# lv3 / 최고의 집합


def solution(n, s):
    if n > s:
        return [-1]
    arr = [s // n for _ in range(n)]
    for i in range(s % n):
        arr[n - 1 - i] += 1
    return arr
