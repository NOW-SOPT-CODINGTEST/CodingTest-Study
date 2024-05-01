def solution(n):
    res = []
    while n:
        tmp = n % 3
        if not tmp:
            tmp = 4
            n -= 1
        res.append(str(tmp))
        n //= 3
    return "".join(res[::-1])
