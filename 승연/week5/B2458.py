from sys import stdin

input = stdin.readline
N, M = map(int, input().split())

s = [([0] * N) for _ in range(N)]
res = 0

for _ in range(M):
    small, big = map(int, input().split())
    s[small - 1][big - 1] = 1

for i in range(N):
    for j in range(N):
        for k in range(N):
            if s[j][i] == 1 and s[i][k] == 1:
                s[j][k] = 1

for i in range(N):
    cnt = 0
    for j in range(N):
        cnt += s[i][j] + s[j][i]
    if cnt == (N - 1):
        res += 1
print(res)
