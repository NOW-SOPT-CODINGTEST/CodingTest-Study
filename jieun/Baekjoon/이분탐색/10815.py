n=int(input())
n_list = list(map(int, input().split()))
m=int(input())
m_list = list(map(int, input().split()))

hash={}
for i in n_list:
    hash[i]=1
for j in m_list:
    if(j in hash):
        print(1, end=' ')
    else:
        print(0, end=' ')