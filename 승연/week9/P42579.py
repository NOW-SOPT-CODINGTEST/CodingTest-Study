# lv3 / 베스트앨범


def solution(genres, plays):
    res = []
    dict = {}
    genDict = {}
    for i in range(len(genres)):
        if genres[i] not in dict:
            genDict[genres[i]] = plays[i]
            dict[genres[i]] = [(plays[i], i)]
        else:
            genDict[genres[i]] += plays[i]
            dict[genres[i]].append((plays[i], i))

    # 제일 큰거 두개
    for i in dict:
        dict[i].sort(key=lambda x: (-x[0], x[1]))
        if len(dict[i]) > 2:
            dict[i] = dict[i][:2]

    genTotal = []
    for i in genDict:
        genTotal.append((i, genDict[i]))
    genTotal.sort(key=lambda x: x[1], reverse=True)

    for i in genTotal:
        for j in dict[i[0]]:
            res.append(j[1])
    return res
