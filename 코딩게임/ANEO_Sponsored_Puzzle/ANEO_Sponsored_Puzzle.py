import sys

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def find_n_level(pass_time,T):
    n = 0
    while(pass_time > T*n):
        n = n + 1
    if pass_time == T*n:
        return n
    else:
        return n-1

speed = int(input())
light_count = int(input())
D = []
T = []
even_check = []
pass_time = 0

for i in range(light_count):
    distance, duration = [int(j) for j in input().split()]
    D.append(distance)
    T.append(duration)

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

for v in range(speed, 0, -1):
    even_check = []
    for i in range(light_count):
        pass_time = (D[i] / v) * 3.6
        if find_n_level(pass_time, T[i]) % 2 == 0:
            even_check.append(1)
    if len(even_check) == light_count:
        break
    
print(v)
