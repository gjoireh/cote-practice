def d(_n):
    dn = _n

    while True:
        if _n == 0:
            break
        else:
            dn += _n % 10
            _n = _n // 10

    # for each_position_number in str(_n):
    #     dn += int(each_position_number)

    return dn


dns = set()


for n in range(1,10001):
    dns.add(d(n))


for i in range(1,10001):
    if i not in dns:
        print(i)
