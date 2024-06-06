def solution(record):
    res = []
    dict = {}
    for i in record:
        log = list(map(str, i.split()))
        if len(log) == 3:
            dict[log[1]] = log[2]
        if log[0] == "Enter":
            res.append((log[1], 0))
        elif log[0] == "Leave":
            res.append((log[1], 1))
    ans = []
    for i in res:
        if i[1] == 0:
            ans.append(dict[i[0]] + "님이 들어왔습니다.")
        else:
            ans.append(dict[i[0]] + "님이 나갔습니다.")
    return ans
