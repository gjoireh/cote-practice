def cal(A):
    ret = 0
    for i in range(len(A) - 1):
        ret += abs(A[i] - A[i + 1])
    return ret


def next_permutation(A):
    i = len(A) - 1

    while i > 0 and A[i - 1] >= A[i]:
        i -= 1

    if i <= 0:
        return False

    j = len(A) - 1
    while A[j] <= A[i-1]: # 여기서 A[i]가 A[i-1]보다 큰 상태이기 때문에 j >= i의 조건을 신경쓸 필요는 없다
        j -= 1

    A[i - 1], A[j] = A[j], A[i - 1]

    j = len(A) - 1
    while i < j:
        A[i], A[j] = A[j], A[i]
        i += 1
        j -= 1
    return True


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0

    A.sort()
    while True:
        temp = cal(A)
        ans = max(ans, temp)
        if not next_permutation(A):
            break
    print(ans)
