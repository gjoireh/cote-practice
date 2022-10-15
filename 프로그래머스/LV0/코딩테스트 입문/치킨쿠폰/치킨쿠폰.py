def solution(chicken):
    return int(chicken/10*(0.1**7 - 1) / (0.1-1))

# def solution(chicken):
#     answer = 0
#     coupon = chicken
#     while coupon >= 10:
#         service = coupon // 10
#         coupon = coupon % 10 + service
#         answer += service
#     return answer