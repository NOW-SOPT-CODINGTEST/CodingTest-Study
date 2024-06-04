# lv3 / 숫자 게임


def solution(A, B):
    A.sort(reverse=True)
    B.sort(reverse=True)
    a, b = 0, 0
    res = 0
    for i in range(len(A)):
        if B[b] > A[a]:
            res += 1
            a += 1
            b += 1
        else:
            a += 1
    return res
