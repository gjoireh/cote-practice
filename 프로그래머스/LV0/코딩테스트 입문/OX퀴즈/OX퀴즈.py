def solution(quiz):
    return ["O" if eval(x.split('=')[0]) == int(x.split('=')[1]) else "X" for x in quiz]