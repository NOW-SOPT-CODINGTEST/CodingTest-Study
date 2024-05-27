# lv3 / 기지국 설치


def solution(n, stations, w):
    homes = [0] * (n)
    cnt = 0
    # 초기 전파 전달되는 곳 표시
    for i in stations:
        if i - 1 - w < 0:
            start = 0
        else:
            start = i - 1 - w
        if i - 1 + w < len(homes):
            end = i - 1 + w
        else:
            end = len(homes) - 1
        for j in range(start, end + 1):
            homes[j] = 1

    while 0 in homes:
        for i in range(n):
            if homes[i] == 0:
                if i + w + w + 1 > len(homes):
                    end = len(homes)
                else:
                    end = i + w + w + 1
                for j in range(i, end):
                    homes[j] = 1
                cnt += 1
                break
    return cnt
