N, M = map(int, input().split())

trees = list(map(int, input().split()))

sum_of_cutted = 0
min, max = 1, max(trees)
height_of_saw = max

while 1:
    sum_of_cutted = 0
    for tree in trees:
        if tree > height_of_saw:
            sum_of_cutted += tree - height_of_saw
    if sum_of_cutted >= M:
        print(height_of_saw)
        break
    height_of_saw -= 1