import re
from collections import Counter
def solution(s):
    return [int(t[0]) for t in sorted(Counter(re.findall('\d+', s)).items(), key=lambda x : x[1], reverse=True)]

# def solution(s):
#     answer = []
#     checked = set()

#     splietted_s = s.lstrip('{').rstrip('}').split("},{")
#     splietted_s = [ss.split(',') for ss in splietted_s]
#     splietted_s.sort(key=len)
#     for ss in splietted_s:
#         for c in ss:
#             if c not in checked:
#                 answer.append(int(c))
#                 checked.add(c)
#     return answer