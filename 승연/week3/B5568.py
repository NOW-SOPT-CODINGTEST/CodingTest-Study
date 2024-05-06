import sys
from itertools import permutations

input = sys.stdin.readline

n = int(input())
k = int(input())
res = set()
cards = []
for _ in range(n):
    cards.append(input().rstrip())
for i in permutations(cards, k):
    res.add("".join(i))
print(len(res))
