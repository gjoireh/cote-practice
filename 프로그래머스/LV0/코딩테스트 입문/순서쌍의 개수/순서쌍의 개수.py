def solution(n):
    answer = len(list(filter(lambda x : n % x == 0, range(1, int(n**(0.5))+1))))
    return (answer-1) * 2 + 1 if n**(0.5) == int(n**(0.5)) else answer * 2

# def solution(n):
#     answer = 0
#     for i in range(1, int(n**(0.5))+1):
#         if n % i == 0:
#             answer += 1
#     return (answer-1) * 2 + 1 if n**(0.5) == int(n**(0.5)) else answer * 2