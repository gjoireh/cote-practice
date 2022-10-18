def solution(i, j, k):
    kc = str(k)
    return sum([ str(i).count(kc) for i in range(i,j+1)])

# def solution(i, j, k):
#     answer = 0
#     kc = str(k)
#     for n in range(i, j+1):
#         for c in str(n):
#             if c == kc:
#                 answer += 1
#     return answer