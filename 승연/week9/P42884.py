# lv3 / 단속카메라


def solution(routes):
    routes.sort(key=lambda x: x[1])
    cam = -30001
    res = 0
    for i in routes:
        if cam < i[0]:
            res += 1
            cam = i[1]
    return res
