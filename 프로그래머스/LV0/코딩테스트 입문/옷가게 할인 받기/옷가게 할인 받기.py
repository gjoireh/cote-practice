def solution(price):
    dr = 0.2

    for i in range(5,0,-2):
        if price >= 100000 * i:
            return int(price * (1-dr))
        dr *= 0.5
    return price

