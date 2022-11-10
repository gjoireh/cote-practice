def solution(a, b, n):
    return (n - b) // (a - b) * b

    
# def solution(a, b, n):
#     answer = 0
#     plus = 0
#     while n // a:
#         plus = (n // a) * b 
#         n = n % a + plus
#         answer += plus
#     return answer