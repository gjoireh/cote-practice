import sys
from collections import deque

N, M, V = map(int, input().split(" "))
graph = {}
for _ in range(M):
    n1, n2 = map(int, sys.stdin.readline().split(" "))
    if n1 not in graph:
        graph[n1] = [n2]
    else:
        graph[n1].append(n2)

    if n2 not in graph:
        graph[n2] = [n1]
    else:
        graph[n2].append(n1)


def dfs_stack(adjacent_graph, start_node):
    stack = [start_node]
    visited = []

    # 시작 노드에 연결된 노드가 없는 경우
    if start_node not in adjacent_graph:
        visited.append(start_node)
        return visited

    while stack:
        current_node = stack.pop()
        # 스택에 중복으로 들어간 노드 제거
        if current_node in visited:
            continue
        visited.append(current_node)
        for adjacent_node in sorted(adjacent_graph[current_node], reverse=True):
            if adjacent_node not in visited:
                stack.append(adjacent_node)
    return visited


def bfs_queue(adjacent_graph, start_node):
    queue = deque()
    queue.append(start_node)
    visited = []

    # 시작 노드에 연결된 노드가 없는 경우
    if start_node not in adjacent_graph:
        visited.append(start_node)
        return visited

    while queue:
        current_node = queue.popleft()
        # 큐에 중복으로 들어간 노드 제거
        if current_node in visited:
            continue
        visited.append(current_node)
        for adjacent_node in sorted(adjacent_graph[current_node]):
            if adjacent_node not in visited:
                queue.append(adjacent_node)
    return visited


dfs = dfs_stack(graph, V)
bfs = bfs_queue(graph, V)

print(" ".join(map(str, dfs)))
print(" ".join(map(str, bfs)))
