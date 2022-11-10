def solution(a, b, n):
    x = 0
    while (n-a) // (a-b) >= x:
        x += 1
    return b * x