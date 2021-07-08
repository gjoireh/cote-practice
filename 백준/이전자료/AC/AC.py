from sys import stdin, stdout

test_case = int(stdin.readline())
command = ""
print_str = ""
for i in range(test_case):
    command = stdin.readline()
    len_of_int_arr = int(stdin.readline())
    int_arr_str = stdin.readline().rstrip()[1:-1].split(',')

    if int_arr_str[0] == '':
        int_arr_str = []

    if command.count('D') > len_of_int_arr:
        stdout.write("error\n")
        continue

    command.replace('RR','')
    rev = 0

    for c in command:
        if c == 'R':
            if rev == 1:
                rev = 0
            else:
                rev = 1
        elif c == 'D':
            if rev == 1:
                int_arr_str.pop(-1)
            else:
                int_arr_str.pop(0)

    if len(int_arr_str) != 0:
        if rev == 1:
            int_arr_str.reverse()

        print_str = "[" + ','.join(int_arr_str) + "]\n"
        stdout.write(print_str)
    else:
        print_str = "[]\n"
        stdout.write(print_str)

