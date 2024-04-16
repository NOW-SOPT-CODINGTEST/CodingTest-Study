start, end = map(int, input().split())

cnt = 1
while start!=end:
    temp = end
    if end%2==0:
        end = end//2
        cnt+=1
    elif end%10 ==1:
        end = end//10
        cnt+=1
    if temp == end:
        print(-1)
        break
# while else문: while 루프가 정상적으로 종료되었을때 else 문 실행.
else:
    print(cnt)
