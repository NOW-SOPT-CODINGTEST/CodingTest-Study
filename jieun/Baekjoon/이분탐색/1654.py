k,m = map(int,input().split())
lan = [int(input()) for _ in range(k)]
start = 1
end = max(lan)

while(start<=end):
    mid = (start+end)//2
    lan_num = 0
    for i in lan:
        lan_num = lan_num + (i//mid)
    if lan_num >= m:
        start = mid+1
    else:
        end = mid-1
print(end)