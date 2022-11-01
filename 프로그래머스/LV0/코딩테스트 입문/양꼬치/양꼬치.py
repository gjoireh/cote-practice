def solution(n, k):
    return 12000 * n if k - n // 10 <= 0 else 12000 * n + (k - n // 10) * 2000