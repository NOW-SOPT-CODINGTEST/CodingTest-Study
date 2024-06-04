# lv2 / 삼각 달팽이


def solution(n):
    snail = [[0] * n for _ in range(n)]
    x, y = 0, 0
    num = 1
    snail[0][0] = 1
    res = []
    for i in range(1, n + 1):
        for j in range(i, n + 1):
            if i % 3 == 1:
                y += 1
            elif i % 3 == 2:
                x += 1
            else:
                x -= 1
                y -= 1
            snail[y - 1][x] = num
            num += 1
    for i in snail:
        for j in i:
            if j != 0:
                res.append(j)
    return res
