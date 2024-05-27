def solution(numbers):
    res = [-1] * len(numbers)
    S = []

    for i in range(len(numbers)):
        while S and numbers[S[-1]] < numbers[i]:
            res[S.pop()] = numbers[i]
        S.append(i)

    return res
