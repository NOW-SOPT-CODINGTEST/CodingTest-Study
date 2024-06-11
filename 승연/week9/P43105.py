# lv3 / 정수 삼각형


def solution(triangle):
    dp = [([0] * len(triangle)) for _ in range(len(triangle))]
    dp[0][0] = triangle[0][0]
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            dp[i][j] += max(
                (dp[i - 1][j - 1] + triangle[i][j]), (dp[i - 1][j] + triangle[i][j])
            )
    return max(dp[i])
