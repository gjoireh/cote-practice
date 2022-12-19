from bisect import bisect_left

def get_all_querys(src, src_idx, query, all_querys):  

    if src_idx == 4:
        all_querys["".join(query)] = []
        return 

    for v in src[src_idx]:
        query.append(v)
        get_all_querys(src, src_idx+1, query, all_querys)
        query.pop()
        
def solution(info, query):
    ans = []
    all_querys = dict()
    src = [['cpp', 'java', 'python', '-'], ['frontend', 'backend', '-'], ['junior', 'senior', '-'], ['chicken', 'pizza', '-']]
    infos = [["".join(info[:-1]), int(info[-1])] for info in [data.split(' ') for data in info]]
    querys = [["".join(query[:-1]), int(query[-1])] for query in [data.replace("and ", '').split(" ") for data in query]]

    get_all_querys(src, 0, [], all_querys)

    for k in list(all_querys.keys()):
        for info in infos:
            for v in k.split('-'):
                if v not in info[0]:break
            else:all_querys[k].append(info[1])

    for k,v in all_querys.items():
        all_querys[k].sort()
    
    for query in querys:
        ans.append(len(all_querys[query[0]]) - bisect_left(all_querys[query[0]], query[1]))
    return ans