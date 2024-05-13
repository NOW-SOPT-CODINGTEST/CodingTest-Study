# 봄버맨
import sys

R, C, N = map(int, sys.stdin.readline().split())
G = [list(sys.stdin.readline().strip()) for _ in range(R)]

if N <= 1:
    for i in G:
        print("".join(i))
elif N % 2 == 0:
    for _ in range(R):
        print("O" * C)
else:
    bomb1 = [["O"] * C for _ in range(R)]
    for y in range(R):
        for x in range(C):
            if G[y][x] == "O":
                bomb1[y][x] = "."
            else:
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if (
                        y + i >= 0
                        and y + i < R
                        and x + j >= 0
                        and x + j < C
                        and G[y + i][x + j] == "O"
                    ):
                        bomb1[y][x] = "."
                        break
    bomb2 = [[0] * C for i in range(R)]
    for y in range(R):
        for x in range(C):
            if bomb1[y][x] == "O":
                bomb2[y][x] = "."
            else:
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if (
                        y + i >= 0
                        and y + i < R
                        and x + j >= 0
                        and x + j < C
                        and G[y + i][x + j] == "O"
                    ):
                        bomb2[y][x] = "."
                        break
    if N % 4 == 3:
        for li in bomb1:
            print("".join(li))
    if N % 4 == 1:
        for li in bomb2:
            print("".join(li))
