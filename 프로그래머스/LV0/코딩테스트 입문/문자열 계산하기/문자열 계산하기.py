def solution(my_string):
    return eval(my_string)

# def solution(my_string):
#     my_string = my_string.split()
#     result = int(my_string[0])
#     temp = 1
#     for i in range(1, len(my_string)):
#         if my_string[i].isdigit():
#             result += int(my_string[i]) * temp
#         elif my_string[i] == '+':
#             temp = 1
#         elif my_string[i] == '-':
#             temp = -1
#     return result

print(solution("3 + 4"))