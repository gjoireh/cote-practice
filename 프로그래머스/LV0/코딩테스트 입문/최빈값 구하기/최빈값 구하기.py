from collections import Counter
def solution(array):
    cnt = Counter(array).most_common()
    return -1 if len(cnt) > 1 and cnt[0][1] == cnt[1][1] else cnt[0][0]