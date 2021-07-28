import sys
from collections import deque


def my_queue(queue, cmd):
    ret = None
    if cmd[0] == "push":
        queue.append(int(cmd[1]))
        return
    elif cmd[0] == "pop":
        if queue:
            ret = queue.popleft()
        else:
            ret = -1
    elif cmd[0] == "size":
        ret = len(queue)
    elif cmd[0] == "empty":
        if queue:
            ret = 0
        else:
            ret = 1
    elif cmd[0] == "front":
        if queue:
            ret = queue[0]
        else:
            ret = -1
    elif cmd[0] == "back":
        if queue:
            ret = queue[-1]
        else:
            ret = -1

    return print(ret)


N = int(input())
queue = deque()
for _ in range(N):
    cmd = sys.stdin.readline().split()
    my_queue(queue, cmd)
