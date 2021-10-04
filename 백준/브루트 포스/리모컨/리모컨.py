buttons = set(map(str, range(0, 10)))
broken_buttons = set()
available_buttons = set()


def is_can_move_by_only_number_button(button_string):
    for c in button_string:
        if c not in available_buttons:
            return False
    return True


if __name__ == "__main__":

    N = input()
    M = int(input())

    if M:
        broken_buttons = set(input().split())
        available_buttons = buttons - broken_buttons
    else:
        available_buttons = buttons

    only_plus_or_minus = abs(int(N) - 100)
    number_button_and_plus_or_minus = 0
    ans = only_plus_or_minus
    int_n = int(N)
    for i in range(0, 1000000):
        if is_can_move_by_only_number_button(str(i)):
            number_button_and_plus_or_minus = len(str(i))
            number_button_and_plus_or_minus += abs(int(N) - i)
            if ans > number_button_and_plus_or_minus:
                ans = number_button_and_plus_or_minus
    print(ans)


