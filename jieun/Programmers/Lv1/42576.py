def solution(participant, completion):
    dict = {}
    for i in participant:
        if i not in dict:
            dict[i] = 1
        else:
            dict[i] += 1
    for j in completion:
        if j in dict:
            dict[j] -= 1
    for k in dict:
        if dict[k]==1:
            answer = k
    return answer
