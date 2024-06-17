def solution(stones, k):
    ppl = 0
    while True:
        for i in range(0, len(stones) - k):
            if sum(stones[i : i + k]) == 0:
                return ppl
        for i in range(len(stones)):
            if stones[i] - 1 >= 0:
                stones[i] -= 1
        ppl += 1


# 징검다리 건너기
# 시간초과
# k 만큼의 합이 가장 작은 구간 찾기?
