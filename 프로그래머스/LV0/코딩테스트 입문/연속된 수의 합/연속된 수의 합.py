def solution(num, total):
    first = (total - (num-1)*num // 2) // num
    return [x for x in range( first, first + num) ]

