from collections import Counter
def solution(before, after):
    return 1 if len(Counter(before) - Counter(after)) == 0 else 0
