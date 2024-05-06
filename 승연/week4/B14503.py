import sys

input = sys.stdin.readline
N, M = map(int, input().split())
x, y, dir = map(int, input().split())
visited = [[False for _ in range(M)] for _ in range(N)]
G = []
res = 0
for i in range(N):
    G.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
while True:
    if not visited[x][y]:
        visited[x][y] = True
        res += 1
    f = False
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < M and G[nx][ny] != 1:
            # 청소되지 않은 빈 칸 없는 경우
            # 청소되지 않은 빈 킨 있는 경우
            if not visited[nx][ny]:
                f = True
                break
        else:
            continue
    if not f:
        newy = y
        newx = x
        if dir == 0:
            newx += 1
        elif dir == 1:
            newy -= 1
        elif dir == 2:
            newx -= 1
        elif dir == 3:
            newy += 1
        # 후진가능? 후진: 멈춤
        if 0 <= newx < N and 0 <= newy < M and G[newx][newy] == 0:
            # 가능
            x = newx
            y = newy
        else:
            print(res)
            exit()
    else:
        # 회전
        newy = y
        newx = x
        if dir == 0:
            dir = 3
            newy -= 1
        elif dir == 1:
            dir = 0
            newx -= 1
        elif dir == 2:
            dir = 1
            newy += 1
        elif dir == 3:
            dir = 2
            newx += 1
        if (
            0 <= newx < N
            and 0 <= newy < M
            and G[newx][newy] == 0
            and not visited[newx][newy]
        ):
            x = newx
            y = newy
