def solution(n, left, right):
    return [i//n + 1 if i // n > i % n else i % n + 1 for i in range(left, right + 1)]

# import numpy as np

# def solution(n, left, right):
#     answer = np.array([])
#     sr = left // n
#     row = np.array(range(1,n+1))
#     row[:sr] = row[sr]
#     answer = np.concatenate([answer, row])

#     for i in range(sr+1, sr + (right - left) // n + 2):
#         row[:i] += 1
#         answer = np.concatenate([answer, row])
#     return list(map(int, answer[left-sr*n:right-sr*n+1]))