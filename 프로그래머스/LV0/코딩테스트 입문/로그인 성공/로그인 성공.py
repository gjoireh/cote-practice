def solution(id_pw, db):
    answer = ''
    ID = id_pw[0]
    PW = id_pw[1] 

    id_pw_dict = dict()
    for idpw in db:
        id_pw_dict[idpw[0]] = idpw[1]

    ids = set([idpw[0] for idpw in db])

    if ID in ids and PW == id_pw_dict[ID]:
        answer = "login"
    elif ID in ids and PW != id_pw_dict[ID]:
        answer = "wrong pw"
    elif ID not in ids:
        answer = "fail"
    
    return answer