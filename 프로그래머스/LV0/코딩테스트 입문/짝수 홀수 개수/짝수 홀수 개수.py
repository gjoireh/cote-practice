import numpy as np

def solution(num_list):
    np_num_list = np.array(num_list)
    return [len(np.where(np_num_list % 2 == 0)[0]), len(np.where(np_num_list % 2 == 1)[0])]