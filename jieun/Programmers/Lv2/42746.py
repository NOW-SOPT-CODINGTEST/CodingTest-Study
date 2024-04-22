from functools import cmp_to_key
def compare(x,y):
    if x+y> y+x:
        return -1
    elif x+y==y+x:
        return 0
    else:
        return 1
def solution(numbers):
    answer = 0
    n = [str(x) for x in numbers]
    n = sorted(n, key=cmp_to_key(compare))
    answer = str(int(''.join(n)))
    return answer

