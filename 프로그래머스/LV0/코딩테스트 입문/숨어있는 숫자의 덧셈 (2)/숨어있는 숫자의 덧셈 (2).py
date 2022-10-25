import re
# pattern = "[a-zA-Z]"
# def solution(my_string):
#     splitted = re.split(pattern, my_string)
#     return sum([int(x) for x in splitted if x.isdigit()])

def solution(s):
    return sum(map(int, re.findall(r'[0-9]+', s)))

