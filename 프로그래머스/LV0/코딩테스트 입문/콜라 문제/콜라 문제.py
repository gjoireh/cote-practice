def solution(a, b, n):
    x = 0
    while n - (a-b) * x >= a:
        x += 1
    return b * x