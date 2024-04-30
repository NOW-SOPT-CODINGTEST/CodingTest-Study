from collections import Counter


def solution(topping):
    res = 0
    one = Counter(topping)
    two = set()

    for i in topping:
        one[i] -= 1
        if one[i] == 0:
            del one[i]
        two.add(i)
        if len(one) == len(two):
            res += 1
    return res
