dn = {"down" : 0, "up" : 1, "left" : 2, "right" : 3}

def solution(keyinput, board):
    global dn
    x, y = 0, 0
    y_move = [-1, 1, 0, 0]
    x_move = [0, 0, -1, 1]
    x_limit = board[0] // 2
    y_limit = board[1] // 2
    for s in keyinput:
        if x + x_move[dn[s]] <= x_limit and x + x_move[dn[s]] >= x_limit*-1:
            x += x_move[dn[s]]
        if y + y_move[dn[s]] <= y_limit and y + y_move[dn[s]] >= y_limit*-1:
            y += y_move[dn[s]]  
    return [x, y]