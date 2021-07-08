import sys

sys.setrecursionlimit(10 ** 9)


def dfs(graph, cur, cur_path_set, cur_path_list, visited, finished):
    global number_of_students_in_team
    cur_path_set.add(cur)
    cur_path_list.append(cur)

    visited[cur] = True
    next_student = graph[cur]
    if finished[next_student]:
        return

    if next_student in cur_path_set:
        if cur == next_student:
            number_of_students_in_team += 1
            finished[cur] = True
            return
        else:
            team = cur_path_list[cur_path_list.index(next_student):]
            number_of_students_in_team += len(team)
            for s in team:
                finished[s] = True
                return
    else:
        if not visited[next_student]:
            dfs(graph, next_student, cur_path_set,cur_path_list, visited, finished)


T = 0
n = 0
T = int(input())

for _ in range(T):
    number_of_students_in_team = 0
    n = int(sys.stdin.readline())
    finished = [False] * (n + 1)
    visited = [False] * (n + 1)
    number_list = list(map(int, sys.stdin.readline().split()))
    number_list.insert(0, None)

    for student in range(1, n + 1):
        cur_path_set = set()
        cur_path_list = []

        if not visited[student] and not finished[number_list[student]]:
            dfs(number_list, student, cur_path_set, cur_path_list,visited, finished)

    print(n - number_of_students_in_team)


