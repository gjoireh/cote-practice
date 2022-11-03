rsp_dict = {'2' : "0", '0' : "5", '5' : "2"}

def solution(rsp):
    return "".join([rsp_dict[c] for c in rsp])