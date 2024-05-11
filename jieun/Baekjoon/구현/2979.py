a,b,c = map(int, input().split())

cnt = [0]*100
answer = 0

for _ in range(3):
    s, e = map(int, input().split())
    for i in range(s, e):
        cnt[i] += 1
    
for i in cnt:
    if i == 1:
        answer += a
    elif i == 2:
        answer += b*2
    elif i == 3:
        answer += c*3

print(answer)