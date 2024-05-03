from collections import deque


def solution(n, computers):
    res = 0
    visited = [False] * n

    def bfs(x):
        Q = deque([x])
        while Q:
            nx = Q.popleft()
            visited[nx] = True
            for i in range(n):
                if computers[nx][i] == 1 and not visited[i]:
                    Q.append(i)
                    visited[i] = True

    for i in range(n):
        print(visited)
        if not visited[i]:
            bfs(i)
            res += 1
    return res
