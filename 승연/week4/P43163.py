from collections import deque


def solution(begin, target, words):
    # 한글자만 다른지 확인
    def isChangable(s1, s2):
        if len(s1) != len(s2):
            return False
        diff = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diff += 1
        if diff == 1:
            return True
        else:
            return False

    # words안에 없음
    if target not in words:
        return 0

    visited = [False] * len(words)
    G = [[] for _ in range(len(words))]

    # 인접 그래프 만들기
    for i in range(len(words)):
        for j in words:
            if isChangable(words[i], j):
                G[i].append(j)
    print(G)

    def bfs(x):
        visited[words.index(x)] = True
        li = deque([[x, 1]])
        print(li)
        while li:
            nx, dist = li.popleft()
            visited[words.index(nx)] = True
            # 찾음
            if nx == target:
                return dist
            for i in G[words.index(nx)]:
                if not visited[words.index(i)]:
                    li.append([i, dist + 1])
                    visited[words.index(i)] = True
        return 0

    ar = []
    resArr = []
    for i in words:
        if isChangable(begin, i):
            ar.append(i)
    for i in ar:
        resArr.append(bfs(i))
    return min(resArr)
