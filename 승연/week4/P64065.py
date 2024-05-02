def solution(s):
    res = []
    ar = s.split("},")
    for i in range(len(ar)):
        ar[i] = list(ar[i].split(","))
        for j in range(len(ar[i])):
            ar[i][j] = int(ar[i][j].replace("{", "").replace("}", ""))
    for i in sorted(ar, key=len):
        for j in i:
            if j not in res:
                res.append(j)
    return res
