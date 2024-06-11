def solution(gems):
    res = [0, len(gems)]
    size = len(set(gems))
    left, right = 0, 0
    dict = {gems[0]: 1}

    while left < len(gems) and right < len(gems):
        if len(dict) == size:
            if right - left < res[1] - res[0]:
                res = [left, right]
            else:
                dict[gems[left]] -= 1
                if dict[gems[left]] == 0:
                    del dict[gems[left]]
                left += 1

        else:
            right += 1
            if right == len(gems):
                break
            dict[gems[right]] = dict.get(gems[right], 0) + 1

    return [res[0] + 1, res[1] + 1]
