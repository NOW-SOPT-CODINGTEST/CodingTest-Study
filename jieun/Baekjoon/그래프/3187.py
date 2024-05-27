from collections import deque


def solution(x, y):
    sheep, wolf = 0, 0
    q.append([x, y])
    visited[x][y] = 1

    while q:
        x, y = q.popleft()
        if graph[x][y] == 'v':
            wolf += 1
        elif graph[x][y] == 'k':
            sheep += 1
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if 0 <= nx < r and 0 <= ny < c and graph[nx][ny] != '#' and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                q.append([nx, ny])
    if wolf >= sheep:
        sheep = 0
    else:
        wolf = 0
    return sheep, wolf


r, c = map(int, input().split())
graph = [[0 for _ in range(c)] for _ in range(r)]
visited = [[0] * c for _ in range(r)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
q = deque()
result_sheep, result_wolf = 0, 0
for _ in range(r):
    graph[_] = list(map(str, input().rstrip()))

for i in range(r):
    for j in range(c):
        if graph[i][j] in ('v', 'k') and visited[i][j] == 0:
            a, b = solution(i, j)
            result_sheep += a
            result_wolf += b
print(result_sheep, result_wolf)