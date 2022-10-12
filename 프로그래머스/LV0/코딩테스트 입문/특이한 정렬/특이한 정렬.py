def solution(numlist, n):
    return sorted(numlist, key=lambda x : (abs(x-n), -x))


# import numpy as np
# def solution(numlist, n):
#     answer = []
#     distances = abs(np.array(numlist)-n)

#     dict1 = dict()

#     for i in range(len(numlist)):
#         if distances[i] not in dict1:
#             dict1[distances[i]] = [numlist[i]]
#         else:
#             dict1[distances[i]].append(numlist[i])

#     lst = list(dict1.keys())
#     lst.sort()

#     for k in lst:
#         answer += sorted(dict1[k], reverse=True)
#     return answer