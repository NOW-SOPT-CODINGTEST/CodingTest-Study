import sys

input = sys.stdin.readline
N = int(input())
ingredient = [list(map(int, input().split())) for i in range(N)]
arr = []
res = 10e9


def dfs(dep, start):
    global res
    if dep == len:
        s, ss = 1, 0
        for i in arr:
            s *= i[0]
            ss += i[1]
        if abs(ss - s) < res:
            res = abs(ss - s)
        return
    for i in range(start, N):
        arr.append(ingredient[i])
        dfs(dep + 1, i + 1)
        arr.pop()


for i in range(1, N + 1):
    len = i
    dfs(0, 0)
print(res)
