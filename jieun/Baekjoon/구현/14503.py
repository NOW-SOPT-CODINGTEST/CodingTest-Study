## 북, 동, 하, 서 ( 시계방향 )
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

n, m = map(int, input().split())
r, c, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
## 방문 체크
visited = [[0]*m for _ in range(n)]

## 시작지 방문체크 & 카운트!
visited[r][c] = 1
cnt = 1

while True:
    flag = 0         
    for _ in range(4):  ## 4방향을 돈다
        d = (d+3) % 4   ## 왼쪽방향으로 한 칸 돌린다
        nr = r + dr[d]
        nc = c + dc[d]

        if 0 <= nr < n and 0 <= nc < m and arr[nr][nc] == 0:
            if visited[nr][nc] == 0:
                visited[nr][nc] = 1
                cnt += 1
                r = nr
                c = nc
                flag = 1       
                break

    if flag == 0:   
        ## 즉 네 방향 모두 청소를 할 수 없을 때
        ## 후진 했을 때 벽이면 break
        ## 만약 뒤가 벽이 아니라면 그 위치를 다시 갱신
        if arr[r-dr[d]][c-dc[d]] == 1:
            print(cnt)
            break
        else:
            r, c = r-dr[d], c-dc[d]