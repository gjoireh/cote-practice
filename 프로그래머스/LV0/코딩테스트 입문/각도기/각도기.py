def solution(angle):
    return 2 * (angle // 90) if angle % 90 == 0 else 2 * (angle // 90) + 1