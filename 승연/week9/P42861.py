def solution(n, costs):
    res = 0
    costs.sort(key=lambda x: x[2])
    list = set([costs[0][0]])
    while len(list) != n:
        for i in costs:
            if i[0] in list and i[1] in list:
                continue
            elif i[0] in list or i[1] in list:
                list.update([i[0], i[1]])
                res += i[2]
                break
    return res
