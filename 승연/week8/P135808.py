# lv1 / 과일 장수


def solution(k, m, score):
    score.sort(reverse=True)
    profit = 0
    n = len(score)

    for i in range(0, n - n % m, m):
        profit += score[i + m - 1] * m

    return profit
