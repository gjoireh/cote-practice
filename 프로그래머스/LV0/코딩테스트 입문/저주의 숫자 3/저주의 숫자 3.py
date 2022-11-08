def solution(n):
    ans = 0
    while n:
        ans += 1
        while ans % 3 == 0 or '3' in str(ans):
            ans += 1
        n -= 1
    return ans

print(solution(40))