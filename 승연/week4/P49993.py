def solution(skill, skill_trees):
    # skill_trees 돌면서 B, D 등 skill 에 skill[0]을 제외한 게 나오면 제외
    res = 0
    for tree in skill_trees:
        idx = 0
        f = True
        for i in tree:
            if i == skill[idx]:
                idx += 1
                if idx == len(skill):
                    break
            elif i in skill[idx + 1 :]:
                f = False
                break

        if f:
            res += 1
    return res
