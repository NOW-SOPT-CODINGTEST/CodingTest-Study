N = int(input())

dp = [0] * max(3, N + 1)
dp[1], dp[2] = 3, 7

for i in range(3, N + 1):
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901

print(dp[N])
