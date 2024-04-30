def solution(want, number, discount):
    res = 0
    for i in range(1, len(discount) - 8):
        flag = True
        for j in range(len(want)):
            if discount[i - 1 : i + 9].count(want[j]) < number[j]:
                flag = False
                break
        if flag:
            res += 1
    return res
