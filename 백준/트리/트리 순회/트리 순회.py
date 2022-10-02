tree = {}

def preoder(node):
    global tree

    if node == '.':
        return  

    print(node, end="")
    preoder(tree[node][0])
    preoder(tree[node][1])

def inoder(node):
    global tree

    if node == '.':
        return  

    inoder(tree[node][0])
    print(node, end="")
    inoder(tree[node][1])


def postorder(node):
    global tree

    if node == '.':
        return  
  
    postorder(tree[node][0])
    postorder(tree[node][1])
    print(node, end="")


N = int(input())

for i in range(N):
    n, l, r = input().split(" ")
    tree[n] = (l,r)

preoder('A')
print("")
inoder('A')
print("")
postorder('A')
print("")