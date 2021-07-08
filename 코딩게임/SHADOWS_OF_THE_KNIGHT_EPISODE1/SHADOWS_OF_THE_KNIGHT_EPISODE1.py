import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def find_idx(list, v):
    for i in range(len(list)):
        if list[i] == v:
            return i

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]

x_list = []
y_list = []

def up(x,y):
    #x_list.append(x)
    y_list.append(y)
    y_list.sort()
    if y_list[0] == y:
        y_min = 0
    else:
        y_min = y_list[find_idx(y_list, y) - 1]

    #if y - y_min == 1:
     #   y_result = y - 1
   
    #else:
    y_result = (y-1) - int(((y-1) - y_min)/2)
    
    x_result = x
    return x_result, y_result

def right(x,y):
    x_list.append(x)
    #y_list.append(y)
    x_list.sort()
    if x_list[len(x_list)-1] == x:
        x_max = w
    else:
        x_max = x_list[find_idx(x_list, x) + 1]

    #if x_max - x == 1:
    #    x_result = x + 1
    
    #else:
    x_result = (x+1) + int((x_max - (x+1))/2)
    y_result = y
    return x_result, y_result

def left(x,y):
    x_list.append(x)
    #y_list.append(y)
    x_list.sort()
    if x_list[0] == x:
        x_min = 0
    else:
        x_min = x_list[find_idx(x_list, x) - 1]
    
    #if x - x_min == 1:
    #    x_result = x -1
   
    #else:
    x_result = (x-1)- int(((x-1) - x_min)/2)

    y_result = y
    return x_result, y_result

def down(x,y):
    #x_list.append(x)
    y_list.append(y)
    y_list.sort()
    if y_list[len(y_list)-1] == y:
        y_max = h
    else:
        y_max = y_list[find_idx(y_list, y)+1]
   
    #if y_max - y == 1:
    #    y_result = y + 1
   
    #else:
    y_result = (y+1) + int((y_max - (y+1))/2)
    x_result = x
    return x_result, y_result

x_current, y_current = x0, y0
x_next, y_next = x0, y0
# game loop
while True:
    bomb_dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    if bomb_dir == "U":
        x_next, y_next = up(x_current, y_current)
    elif bomb_dir == "R":
        x_next, y_next = right(x_current, y_current)
    elif bomb_dir == "L":
        x_next, y_next = left(x_current, y_current)
    elif bomb_dir == "D":
        x_next, y_next = down(x_current, y_current)
    elif bomb_dir == "UR":
        x_next, y_next = up(x_current, y_current)
        x_next, y_next = right(x_next, y_next)
    elif bomb_dir == "UL":
        x_next, y_next = up(x_current, y_current)
        x_next, y_next = left(x_next, y_next)
    elif bomb_dir == "DR":
        x_next, y_next = down(x_current, y_current)
        x_next, y_next = right(x_next, y_next)
    elif bomb_dir == "DL":
        x_next, y_next = down(x_current, y_current)
        x_next, y_next = left(x_next, y_next)
    # the location of the next window Batman should jump to.
    print("{0} {1}".format(x_next, y_next))
    x_current, y_current = x_next, y_next