import heapq


def solution(operations):
    H = []
    for o in operations:
        f, num = o.split()
        if f == "I":
            heapq.heappush(H, int(num))
        else:
            if num == "1":
                # 최댓값 삭제
                if H:
                    H.pop()
            else:
                # 최솟값 삭제
                if H:
                    heapq.heappop(H)
    if H:
        return [max(H), min(H)]
    else:
        return [0, 0]
