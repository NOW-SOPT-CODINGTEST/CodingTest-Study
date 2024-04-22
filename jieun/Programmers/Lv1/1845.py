def solution(nums):
    answer = 0
    if len(set(nums))>len(nums)/2:
        answer = round(len(nums)/2)
    else:
        answer = len(set(nums))
    return answer

print(solution([3,1,2,3]))