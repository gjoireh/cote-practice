n = int(input())
triangle = []

# 삼각형 입력 받고
for _ in range(n):
    line = list(map(int, input().split()))
    triangle.append(line)

# 각 삼각형 자리를 지나가면서 각 위치를 각 위치에 올 수 있는 최대값으로 변경(메모)
for line in range(1,n):
    for i in range(len(triangle[line])):
        
        if i == 0:                                      # 맨 왼쪽자리의 경우 윗줄의 첫번째 값을 더해주면 되고
            triangle[line][0] += triangle[line-1][0]
        
        elif i == (len(triangle[line])-1):              # 맨 오른쪽자리의 경우 윗줄의 맨 오른쪽 값을 더해주면 되고
            triangle[line][i] += triangle[line-1][i-1]
        
        else:                                           # 그 외는 윗줄의 왼쪽과 오른쪽중 큰 값을 더해 넣으면 된다.
            triangle[line][i] += max(triangle[line-1][i - 1], triangle[line-1][i])
print(max(triangle[n-1]))







