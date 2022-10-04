def dangerous_area_record(board, d_place, x, y, n):
    for i in range(x-1, x+2):
        for j in range(y-1, y+2):
            if i < 0 or i > n-1 or j < 0 or j > n-1:
                continue
            d_place[i][j] = True

def get_num_of_safe_place(d_place, n):
    cnt = 0
    for i in range(n):
        for j in range(n):
            if d_place[i][j] == False:
                cnt += 1
    return cnt

def solution(board):
    n = len(board[0])
    d_place = []
    for i in range(n):
        d_place.append([False]*n)

    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                dangerous_area_record(board, d_place, i, j, n)

    answer = get_num_of_safe_place(d_place, n)
    return answer