def solution(n):
    i = 2
    ans = []
    while n > 1:
        if n % i == 0:
            ans.append(i)
            while n % i == 0:
                n //= i
        i += 1
    return ans

# def sieve_of_eratosthenes(n):
#     sieve = [True] * (n+1)

#     m = int(n ** 0.5)
#     for i in range(2, m + 1):
#         if sieve[i] == True:
#             for j in range(i+i, n+1, i):
#                 sieve[j] = False
#     return [i for i in range(2, n+1) if sieve[i] == True]

# def solution(n):
#     pl = sieve_of_eratosthenes(n)
#     return [p for p in pl if n % p == 0]