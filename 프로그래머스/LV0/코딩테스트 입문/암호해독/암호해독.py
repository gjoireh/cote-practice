def solution(cipher, code):
    answer = cipher[code-1::code]
    return answer
    
# def solution(cipher, code):
#     answer = ''
#     i = 1
#     for c in cipher:
#         if i % code == 0:
#             answer += c
#         i += 1
#     return answer