# def get_divisors(x):
#     ret = set()
#     mid_val = x**(0.5)
#     if mid_val % 1 == 0:
#         for i in range(1, int(mid_val)):
#             if x % i == 0:
#                 ret.add(i)
#                 ret.add(x // i)
#         ret.add(int(mid_val))
#     else:
#         for i in range(1, int(mid_val)+1):
#             if x % i == 0:
#                 ret.add(i)
#                 ret.add(x // i)
#     return ret

# def get_lcm(n,m,gcd):
#     return n* m // gcd


# def solution(n, m):
#     answer = []
#     n_divisors = get_divisors(n)
#     m_divisors = get_divisors(m)
#     n_m_divisors = n_divisors & m_divisors
#     gcd = max(n_m_divisors)
#     answer.append(gcd)
#     answer.append(get_lcm(n,m,gcd))
#     return answer

# import math
# def solution(n,m):
#     gcd = math.gcd(n,m)
#     return [gcd, n*m//gcd]

def get_gcd(m,n):
    while n != 0:
       t = m%n
       (m,n) = (n,t)
    return abs(m)

def solution(n,m):
    gcd = get_gcd(n,m)
    return [gcd, n*m//gcd]

print(solution(3,12))
print(solution(1,10))