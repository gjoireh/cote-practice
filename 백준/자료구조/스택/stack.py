import sys
def my_stack(stack, cmd):
    ret = None
    if cmd[0] == "push":
        stack.append(int(cmd[1]))
        return
    elif cmd[0] == "pop":
        if stack:
            ret = stack.pop()
        else:
            ret = -1
    elif cmd[0] == "size":
        ret = len(stack)
    elif cmd[0] == "empty":
        if stack:
            ret = 0
        else:
            ret = 1
    elif cmd[0] == "top":
        if stack:
            ret = stack[-1]
        else:
            ret = -1

    return print(ret)


N = int(input())
stack = []
for _ in range(N):
    cmd = sys.stdin.readline().split()
    my_stack(stack, cmd)
