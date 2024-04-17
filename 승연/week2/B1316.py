import sys

input = sys.stdin.readline

N = int(input())
cnt = 0
for _ in range(N):
    word = input()
    arr = []
    f = True
    for i in word:
        if i not in arr:
            arr.append(i)
        else:
            if arr and arr[-1] == i:
                continue
            else:
                f = False
                break
    if f:
        cnt += 1
print(cnt)
