# RGB거리
import sys

N = int(sys.stdin.readline().rstrip())
houses = [[-1, -1, -1]]
for _ in range(N):
    houses.append(list(map(int, sys.stdin.readline().rstrip().split())))

R, G, B = 0, 1, 2

dp = [[-1] * 3 for _ in range(N+1)]
dp[1] = houses[1]

for i in range(2, N+1):
    dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + houses[i][R]
    dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + houses[i][G]
    dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + houses[i][B]

print(min(dp[N]))
