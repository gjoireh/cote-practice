import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.


budgets = []
n = int(input())
c = int(input())
for i in range(n):
    budgets.append(int(input()))

budgets = sorted(budgets)
remaining = n
if sum(budgets) < c:
    print("IMPOSSIBLE")
else:
    for i in range(n):
        budget = budgets[i]
        avg = c // remaining
        if budget < avg:
            c -= budget
            print(budget)
        else:
            c -= avg
            print(avg)
        remaining -= 1

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)