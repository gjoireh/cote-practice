import sys
inputs = []
selected_two = []
answer = []

for i in range(9):
    inputs.append(int(sys.stdin.readline()))

for i in range(8):
    for j in range(i+1, 9):
        selected_two.append([inputs[i],inputs[j]])

for st in selected_two:
    if sum(set(inputs) - set(st)) == 100:
        answer = list(set(inputs) - set(st))
        break

answer.sort()
for ans in answer:
    print(ans)

