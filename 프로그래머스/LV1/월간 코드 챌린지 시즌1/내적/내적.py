import numpy as np

def solution(a, b):
    l1 = np.array(a)
    l2 = np.array(b)
    answer = np.multiply(l1,l2).tolist()
    return sum(answer)