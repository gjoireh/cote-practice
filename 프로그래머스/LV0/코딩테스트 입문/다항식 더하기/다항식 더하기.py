def solution(polynomial):
    x = 0
    n = 0
    p = polynomial.split(" + ")

    for s in p:
        if "x" in s:
            x += 1 if s == "x" else int(s[:s.index('x')])
        else:
            n += int(s)

    answer = [[str(0), "x" if x == 1 else f"{x}x"],[str(n), f"x + {n}" if x == 1 else str(x) + f"x + {n}"]]
    return answer[n > 0][x > 0]