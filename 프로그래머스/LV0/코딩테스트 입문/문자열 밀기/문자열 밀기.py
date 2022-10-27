def solution(A, B):
    return (2*B).find(A)
    
# def shift(A, B, a_len, ans):
#     if A == B:
#         return ans
#     if ans == a_len:
#         ans = -1
#         return ans
#     A = A[-1] + A[:-1]
#     return shift(A, B, a_len, ans+1)

# def solution(A, B):
#     return shift(A, B, len(A), 0)
