import math
# from math import sqrt, pow

T = int(input())
line = []
for _ in range(T):
    line = list(map(int,input().split(" ")))
    employee1 = tuple(line[0:2])
    distance_from_employee1_to_marin = line[2]
    employee2 = tuple(line[3:5])
    distance_from_employee2_to_marin = line[5]
    distance_between_two_employees = math.sqrt(math.pow(employee1[0] - employee2[0], 2) +
                                               math.pow(employee1[1] - employee2[1], 2))
    if distance_from_employee1_to_marin > distance_from_employee2_to_marin:
        r1 = distance_from_employee1_to_marin
        r2 = distance_from_employee2_to_marin
    else:
        r1 = distance_from_employee2_to_marin
        r2 = distance_from_employee1_to_marin
    d = distance_between_two_employees

    if d == 0 and r1 == r2:
        print(-1)
    elif d == 0 and r1 != r2:
        print(0)
    elif (r1 - r2) < d < (r1 + r2):
        print(2)
    elif r1 + r2 == d:
        print(1)
    elif r1 - r2 == d:
        print(1)
    elif r1 + r2 < d:
        print(0)
    elif r1 - r2 > d:
        print(0)





