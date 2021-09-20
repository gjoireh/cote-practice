import sys

N, M = map(int, input().split())
NS = []
MS = []

for _ in range(N):
    NS.append(sys.stdin.readline().rstrip())

for _ in range(M):
    MS.append(sys.stdin.readline().rstrip())

NS.sort()

answer = 0

for M in MS:
    left = 0
    right = N - 1
    mid = right // 2
    len_of_M = len(M)
    while left <= right:
        if NS[mid][:len_of_M] == M:
            answer += 1
            break

        if NS[mid] < M:
            left = mid + 1
            mid = (left + right) // 2
        else:
            right = mid - 1
            mid = (left + right) // 2


print(answer)