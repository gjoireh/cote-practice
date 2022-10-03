def same_continuos(b):
    if "ayaaya" in b or "yeye" in b or "woowoo" in b or "mama" in b:
        return True
    return False

def impossible_pronounce(b):
    b = b.replace("aya", "")
    b = b.replace("ye", "")
    b = b.replace("woo", "")
    b = b.replace("ma", "")
    if len(b) != 0:
        return True
    else:
        return False

def solution(babbling):
    answer = 0
    for b in babbling:
        if same_continuos(b):
            continue
        if impossible_pronounce(b):
            continue
        answer += 1
    return answer