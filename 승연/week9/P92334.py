def solution(id_list, report, k):
    dict = {}
    reports = {}
    res = []

    for i in id_list:
        reports[i] = 0
        dict[i] = set()

    for i in report:
        log = i.split()
        dict[log[0]].add(log[1])

    for i in dict:
        for j in dict[i]:
            reports[j] += 1
    for i in reports:
        if reports[i] >= k:
            reports[i] = -1

    for i in id_list:
        cnt = 0
        for j in dict[i]:
            if reports[j] == -1:
                cnt += 1
        res.append(cnt)
    return res
