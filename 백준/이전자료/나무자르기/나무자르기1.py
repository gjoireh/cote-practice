N, M = map(int, input().split())

trees = list(map(int, input().split()))

sum_of_cutted = 0
min, max = 1, max(trees)


while min <= max:
    sum_of_cutted = 0
    height_of_saw = (max + min) // 2

    for tree in trees:
        if tree > height_of_saw:
            sum_of_cutted += tree - height_of_saw

    if sum_of_cutted >= M:
        min = height_of_saw + 1
    else:
        max = height_of_saw - 1
print(max)