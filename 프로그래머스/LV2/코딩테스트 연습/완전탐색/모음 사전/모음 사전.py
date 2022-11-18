previous_count = {'A' : 0, 'E' : 1, 'I' : 2, 'O' : 3, 'U' : 4}

def solution(word):
    answer = 0
    for i, n in enumerate(word):
        answer += ((5 * (5**(4-i) - 1) // 4) + 1) * previous_count[n] + 1
    return answer

# vowel = ['A', 'E', 'I', 'O', 'U']
# answer = 0
# fin = False

# def go(select, s, word):
#     global answer, fin

#     if fin:
#         return
#     if s == word:
#         fin = True
#         return

#     answer += 1

#     if select == 5:
#         return

#     for v in vowel:
#         go(select + 1,  s + v, word)

# def solution(word):
#     global answer
#     go(0, "", word)
#     return answer
