def solution(emergency):
    return [sorted(emergency,reverse=True).index(i)+1 for i in emergency]

# def solution(e):
#     emdict = dict.fromkeys(e,0)
#     e.sort(reverse=True)
#     for i in range(len(e)):
#         emdict[e[i]] = i + 1
#     return list(emdict.values())
