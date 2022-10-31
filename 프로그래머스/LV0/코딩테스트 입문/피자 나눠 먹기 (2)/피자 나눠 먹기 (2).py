from math import gcd

def solution(n):
    return n // gcd(n, 6)


# def solution(n):
#     pizza = 1
#     while True:
#         if 6 * pizza % n == 0:
#             break
#         pizza += 1
#     return pizza