import sys

N = 0
S = []
team1 = []
team2 = []
diffs = []


def stop(t1, t2):
    if len(t1) > N // 2 or len(t2) > N // 2:
        return True
    return False


def save_diff(t1, t2):
    sum_of_t1 = 0
    sum_of_t2 = 0
    for i in range(N // 2):
        for j in range(N // 2):
            if i == j:
                continue
            sum_of_t1 += S[t1[i]][t1[j]]
            sum_of_t2 += S[t2[i]][t2[j]]
    diff = abs(sum_of_t1 - sum_of_t2)
    diffs.append(diff)
    return


def make_team(index, t1, t2):
    if index == N:
        if len(t1) == N // 2 and len(t2) == N // 2:
            return True
        else:
            return False

    if stop(t1, t2):
        return False

    t1.append(index)
    if make_team(index + 1, t1, t2):
        save_diff(t1, t2)
    t1.pop()

    t2.append(index)
    if make_team(index + 1, t1, t2):
        save_diff(t1, t2)
    t2.pop()
    return False


if __name__ == "__main__":
    N = int(input())
    for i in range(N):
        S.append(list(map(int, sys.stdin.readline().split())))

    make_team(0, team1, team2)
    print(min(diffs))
