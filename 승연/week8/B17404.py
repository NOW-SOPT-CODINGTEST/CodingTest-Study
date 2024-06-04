import sys

input = sys.stdin.readline

N = int(input())
RGB = [list(map(int, input().split())) for _ in range(N)]
res = 10e9

for i in range(3):
    dp = [[10e9] * 3 for _ in range(N)]
    dp[0][i] = RGB[0][i]
    for j in range(1, N):
        dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + RGB[j][0]
        dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + RGB[j][1]
        dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + RGB[j][2]
    dp[-1][i] = 10e9
    res = min(res, min(dp[-1]))
print(res)
