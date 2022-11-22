def solution(number, k):
    stack = []

    for n in number:
        while stack and k > 0 and stack[-1] < n:
            stack.pop()
            k -= 1
        stack.append(n)

    if k:
        return number[:len(number)-k]
    return ''.join(stack)

# def solution(number, k):
#     ans = ""
#     ans_len = len(number) - k
#     cur_len = 0

#     sorted_number = sorted(number, reverse=True)
    
#     while k:
#         if cur_len == ans_len:
#             break
#         for c in sorted_number:
#             idx = number.find(c)
#             if idx == -1:
#                 continue
#             elif idx == k:
#                 ans += number[idx:]
#                 k = 0
#                 break
#             elif idx < k:
#                 number = number[idx+1:]
#                 ans += c
#                 cur_len += 1
#                 k -= idx
#                 break
#     return ans