def solution(lines):
    answer = 0
    temp_cnt = 0
    total = []

    for l in lines:
        total += l
    
    for l in lines:
        l.sort()

    for i in range(min(total), max(total)):
        for l in lines:
            if l[0] <= i and l[1] >= i+1:
                temp_cnt += 1
        if temp_cnt > 1:
            answer += 1
        temp_cnt = 0
    return answer