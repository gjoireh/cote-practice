used = set()
each_case = [0] * 8


def go(index, n, m):

    if index == m:
        for i in range(m):
            if i == m-1:
                print(str(each_case[i]))
            else:
                print(str(each_case[i]) + " ",end="")
        return

    for i in range(1,n+1):
        if i in used:
            continue
        used.add(i)
        each_case[index] = i
        go(index + 1, n, m)
        used.remove(i)


if __name__ == "__main__":

    n, m = map(int, input().split())
    go(0, n, m)
