def solution(n, times):
    start = 1
    end = max(times) * n

    while start <= end:
        mid = (start + end) // 2
        ppl = 0

        for i in times:
            ppl += mid // i
            if ppl >= n:
                break

        if ppl >= n:
            res = mid
            end = mid - 1
        else:
            start = mid + 1

    return res
