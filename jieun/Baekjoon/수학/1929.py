n,m = map(int, input().split())

a = [False]*(2) + [True]*(m-1)
primes = []

for i in range(2,m+1):
    if a[i]:
        primes.append(i)
        for j in range(2*i, m+1, i):
            a[j]= False
for i in primes:
    if i>=n:
        print(i)