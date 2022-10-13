def solution(score):
    answer = []
    
    score = [sum(s) for s in score]
    sorted_score = sorted(score, reverse=True)

    dict1 = dict()
    for i,ss in enumerate(sorted_score):
        if ss not in dict1:
            dict1[ss] = i + 1

    answer = [dict1[s] for s in score]
    return answer



# def solution(score):
#     answer = []

#     score = [sum(s) for s in score]
#     sorted_score = sorted(score, reverse=True)

#     dict1 = dict()
#     i = 1
#     for ss in sorted_score:
#         if ss not in dict1:
#             dict1[ss] = i
#         i += 1

#     answer = [dict1[s] for s in score]
#     return answer