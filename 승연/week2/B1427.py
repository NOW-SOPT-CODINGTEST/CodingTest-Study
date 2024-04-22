import sys

input = sys.stdin.readline
N = sorted(input().rstrip(), reverse=True)
print("".join(N))
