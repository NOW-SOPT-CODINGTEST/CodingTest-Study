arr = sorted(list(int(input()) for _ in range(9)))

S = sum(arr)


def findPair():
    for i in range(9):
        for j in range(i + 1, 9):
            if S - arr[i] - arr[j] == 100:
                del arr[i]
                del arr[j - 1]
                return


findPair()
for i in arr:
    print(i)
