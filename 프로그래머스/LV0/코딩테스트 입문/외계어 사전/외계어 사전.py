def solution(spell, dic):
    len_of_spell = len(spell)
    spell_sum = 0
    word_sum = 0
    
    for i in range(len_of_spell):
        spell_sum += ord(spell[i])
        
    for w in dic:
        word_sum = 0
        if len(w) != len_of_spell:
            continue
        
        for i in range(len_of_spell):
            word_sum += ord(w[i])

        if spell_sum == word_sum:
            return 1
    return 2