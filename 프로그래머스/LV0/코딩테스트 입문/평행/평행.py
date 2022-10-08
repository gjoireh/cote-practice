import numpy as np
from itertools import combinations

def solution(dots):
    np_dots = np.array(dots)
    select = list(combinations(range(4),2))
    
    for i in range(3):
        sub1 = np_dots[select[i][0]] - np_dots[select[i][1]]
        sub2 = np_dots[select[5-i][0]] - np_dots[select[5-i][1]]

        if (sub1[1] == 0 and sub2[1] != 0) or (sub1[0] != 0 and sub2[0] == 0):
            continue

        if ((sub1[1] == 0 and sub2[1] == 0) or
            (sub1[0] == 0 and sub2[0] == 0) or
            (sub1[0] / sub1[1]) == (sub2[0] / sub2[1])):
            return 1
    return 0

