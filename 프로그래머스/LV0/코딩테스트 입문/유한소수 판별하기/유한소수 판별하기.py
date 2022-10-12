def solution(a, b):
    return 1 if a/b * 1000 % 1 == 0 else 2

# from math import gcd, sqrt

# def is_prime_number(x):
#     for i in range(2, int(sqrt(x)) + 1):
#         if x % i == 0:
#             return False
#     return True

# def solution(a, b):
#     prime_factors = []

#     denominator = b // gcd(a,b)
#     if denominator == 2:
#         return 1

#     for i in range(2, denominator + 1):
#         if denominator % i == 0 and is_prime_number(i):
#             prime_factors.append(i)

#     for pf in prime_factors:
#         if pf != 2 and pf != 5:
#             return 2

#     return 1