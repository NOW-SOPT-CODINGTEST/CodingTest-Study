ppl = list(map(int, input().split()))
dishes = list(map(int, input().split()))
res = 0
for i in range(3):
    if dishes[i] > ppl[i]:
        res += dishes[i] - ppl[i]
print(res)
