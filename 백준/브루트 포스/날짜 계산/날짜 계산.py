def cal_date(E, S, M):
    e, s, m, y = 0, 0, 0, 0

    while True:
        y += 1
        e += 1
        s += 1
        m += 1

        if e > 15:
            e = 1
        if s > 28:
            s = 1
        if m > 19:
            m = 1

        if e == E and s == S and m == M:
            return y


if __name__ == "__main__":
    E, S, M = map(int, input().split())
    year = cal_date(E, S, M)
    print(year)
