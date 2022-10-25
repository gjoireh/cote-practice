from math import gcd
def solution(denum1, num1, denum2, num2):
    numerator = denum1*num2 + denum2*num1
    denominator = num1*num2
    g = gcd(numerator, denominator)
    return [numerator//g,denominator//g]

