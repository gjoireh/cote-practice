import math

answer = 0
prime_numbers = set()
used = set()


def is_prime_number(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

# 4C2
def go(j, cnt, n, m, nums):
    global answer
    if cnt == m:
        if is_prime_number(sum(used)):
            answer += 1
        return

    for i in range(j, n):
        used.add(nums[i])
        go(i+1, cnt + 1, n, m, nums)
        used.remove(nums[i])

# 4P2
# def go(cnt, n, m, nums):
#     global answer
#     if cnt == m:
#         if is_prime_number(sum(used)):
#             answer += 1
#         return
#
#     for i in range(n):
#         if nums[i] in used:
#             continue
#         used.add(nums[i])
#         go(cnt + 1, n, m, nums)
#         used.remove(nums[i])

def solution(nums):
    global answer
    # 4P2
    # go(0, len(nums), 3, nums)

    # 4C2
    go(0, 0, len(nums), 3, nums)
    return answer

