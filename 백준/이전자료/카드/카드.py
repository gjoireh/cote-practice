from sys import stdin

N = int(stdin.readline())
cards = []
each_cards_num_dict = {}
max_v = 0

for i in range(N):
    temp = int(stdin.readline())
    cards.append(temp)

cards.sort()

for c in cards:
    if c not in each_cards_num_dict:
        each_cards_num_dict[c] = 1
    else:
        each_cards_num_dict[c] += 1
max_v = max(each_cards_num_dict.values())
key_list = list(each_cards_num_dict.keys())
key_list.sort()
for k in key_list:
    if each_cards_num_dict[k] == max_v:
        print(k)
        break
