from bisect import bisect_left

def get_all_queries_derived_from_info(input_info, all_mask, score, aqdfi):
    q = ""
    for i in range(4):
        q += '-' if (all_mask & (1 << i)) else input_info[i]

    if q not in aqdfi:aqdfi[q] = [score]
    else:aqdfi[q].append(score)

def solution(info, query):
    ans = []
    all_queries_derived_from_info = dict() 
    input_info = ["", "", "", ""]
    
    for _info in info:
        input_info[0], input_info[1], input_info[2], input_info[3], score = _info.split(' ')
        for i in range(16):
            get_all_queries_derived_from_info(input_info, i, int(score), all_queries_derived_from_info)

    for k,_ in all_queries_derived_from_info.items():
        all_queries_derived_from_info[k].sort()
    
    for _query in query:
        input_info[0], _, input_info[1], _, input_info[2], _, input_info[3], score = _query.split(' ')
        q = "".join(input_info)
        if q not in all_queries_derived_from_info:all_queries_derived_from_info[q] = []
        ans.append(len(all_queries_derived_from_info[q]) - bisect_left(all_queries_derived_from_info[q], int(score)))
    return ans