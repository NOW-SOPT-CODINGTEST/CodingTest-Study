import sys
import math

input = sys.stdin.readline
N, M, K = map(int, input().split())
G = [[[] for _ in range(N + 1)] for _ in range(N + 1)]
for _ in range(M):
    row, col, m, s, d = map(int, input().split())
    G[row][col].append([m, s, d])


def move(s, d):
    x, y = 0, 0
    if d == 0:
        x, y = 0, 1
    elif d == 1:
        x, y = 1, 1
    elif d == 2:
        x, y = 1, 0
    elif d == 3:
        x, y = 1, -1
    elif d == 4:
        x, y = 0, -1
    elif d == 5:
        x, y = -1, -1
    elif d == 6:
        x, y = -1, 0
    else:
        x, y = -1, 1
    return (x * s, y * s)


def splitBalls(balls):
    newBalls = []
    mass = 0
    speed = 0
    even = True
    odd = True
    for ball in balls:
        mass += ball[0]
        speed += ball[1]
        if ball[2] % 2:
            odd = False
        else:
            even = False
    # 없어짐
    if mass == 0:
        return []
    nmass = math.floor(mass / 5)
    nspeed = math.floor(speed / len(balls))
    if odd or even:
        for i in [0, 2, 4, 6]:
            newBalls.append([nmass, nspeed, i])
    else:
        for i in [1, 3, 5, 7]:
            newBalls.append([nmass, nspeed, i])
    return newBalls


# k번 반복
for _ in range(K):
    NG = [[[] for _ in range(N + 1)] for _ in range(N + 1)]
    # 이동
    for i in range(N + 1):
        for j in range(N + 1):
            while G[i][j]:  # while 문을 사용하여 안전하게 처리
                ball = G[i][j].pop(0)
                # 0:x, 1:y
                mx, my = move(ball[1], ball[2])
                NG[(my + i) % N][(mx + j) % N].append(ball)
    G = NG

    # 같은 자리에 겹쳤는지 확인
    for i in range(N + 1):
        for j in range(N + 1):
            # 겹침!
            if len(G[i][j]) > 1:
                G[i][j] = splitBalls(G[i][j])

# 합 계산하기
sum = 0
for i in range(N + 1):
    for j in range(N + 1):
        while G[i][j]:
            ball = G[i][j].pop(0)
            sum += ball[0]

print(sum)
