def solution(hp):
    answer = 0
    for damage in range(5, 0, -2):
        answer += hp // damage
        hp %= damage
    return answer

