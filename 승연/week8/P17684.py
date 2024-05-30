def solution(msg):
    arr = []
    for i in msg:
        arr.append(i)
    dict = {chr(i + 65): i + 1 for i in range(26)}

    base = ""
    val = 26
    res = [0]

    for i in arr:
        base += i
        if base not in dict:
            res.append(dict.get(i))
            val += 1
            dict[base] = val
            base = i
        else:
            res[-1] = dict.get(base)
    return res
