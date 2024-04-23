import sys

input = sys.stdin.readline

N = int(input())
s, g, p, d = map(int, input().split())
rank = input()
res = [0]

for i in range(len(rank) - 1):
    if rank[i] == "B":
        res.append(s - res[-1] - 1)
    elif rank[i] == "S":
        res.append(g - res[-1] - 1)
    elif rank[i] == "G":
        res.append(p - res[-1] - 1)
    elif rank[i] == "P":
        res.append(d - res[-1] - 1)
    else:
        res.append(d)
print(sum(res))
