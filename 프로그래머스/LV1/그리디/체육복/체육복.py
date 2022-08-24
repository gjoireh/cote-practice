def solution(n, lost, reserve):
    only_lost = set(lost) - set(reserve)
    only_reserve = set(reserve) - set(lost)

    answer = n - len(only_lost)

    for r in list(only_reserve):
        if r-1 in only_lost:
            only_lost.remove(r-1)
            answer += 1
        elif r+1 in only_lost:
            only_lost.remove(r+1)
            answer += 1
    return answer