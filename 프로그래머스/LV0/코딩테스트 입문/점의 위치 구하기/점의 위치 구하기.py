def solution(dot):
    quad = [(3,2),(4,1)]
    return quad[dot[0] > 0][dot[1] > 0]

# def solution(dot):
#     if dot[0] * dot[1] > 0 and dot[0] > 0:
#         return 1
#     elif dot[0] * dot[1] > 0 and dot[0] < 0:
#         return 3
#     elif dot[0] * dot[1] < 0 and dot[0] < 0:
#         return 2
#     else:
#         return 4
