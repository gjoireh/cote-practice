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
        print(used)
        if is_prime_number(sum(used)):
            answer += 1
        return

    for i in range(j, n):
        if nums[i] in used:
            continue
        used.add(nums[i])
        go(i+1, cnt + 1, n, m, nums)
        used.remove(nums[i])

# 4P2
# def go(cnt, n, m, nums):
#     global answer
#     if cnt == m:
#         print(used)
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


print(solution([1,2,7,6,4]))

# used = set()
# each_case = [0] * 8
#
#
# def go(index, n, m):
#
#     if index == m:
#         print(used)
#         # for i in range(m):
#
#             # if i == m-1:
#             #     print(str(each_case[i]))
#             # else:
#             #     print(str(each_case[i]) + " ",end="")
#         return
#
#     for i in range(1,n+1):
#         if i in used:
#             continue
#         used.add(i)
#         each_case[index] = i
#         go(index + 1, n, m)
#         used.remove(i)
#
#
# if __name__ == "__main__":
#
#     n, m = map(int, input().split())
#     go(0, n, m)