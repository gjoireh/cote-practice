def solution(s):
    s = s.split(' ')
    ans = 0
    adds = []
    
    for c in s:
        if c != 'Z':
            last_add = int(c) 
            adds.append(last_add) 
            ans += last_add
        else:
            if len(adds) == 0:
                continue
            ans -= adds.pop()
    return ans
