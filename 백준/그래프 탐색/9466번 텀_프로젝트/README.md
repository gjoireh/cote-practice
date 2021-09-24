## 텀 프로젝트
### 재귀 DFS, 스택 DFS
1~n번의 학생을 돌면서 각 학생의 연결된 경로 확인,  
진행하면서 방문한곳, 현재 경로, 팀을 이룬 학생을 표시하고  
DFS를 진행하다가 방문한곳이나 팀을 이룬 학생에 오면 더 진행하지 않는다.  

채점중 78,79% 정도에서 시간초과가 계속 난다. 일단 질문 해놓고 계속 확인해 볼것  


* 결과  
1. next_student, 다음 학생이 cur_path에 있는지 in 으로 확인할때 list를 쓰면 list가 길이가 n일때 n 시간복잡도, set()을 사용하면 1,  
이전에는 리스트를 사용하면서 in으로 연산하고 있었기 때문에 O(n^2)의 시간복잡도를 갖게됨, set 사용시 O(n)  
2. 그리고 결정적으로 다음 학생이 cur_path에 있는지만 확인하고 그렇지 않다면 dfs를 계속 진행했는데
```
        if next_student in cur_path_set:
            if current_number == next_student:
            
            .
            .
            .

        else:
            stack.append(next_student)
```
다음 학생이 cur_path에 없더라도 이전에 다른 경로에서 방문 했을 수 있다. 이 경우를 제외하지 않고 있었다.  
```
        if next_student in cur_path_set:
            if current_number == next_student:
            
            .
            .
            .

        else:
            if not visited[next_student]:
                stack.append(next_student)
```


* dfs, 스택, 재귀
한가지 눈에 띄는게 dfs를 스택으로 구현하면 재귀에비해 사용 메모리양이 절반 이상으로 줄어든다. 시간은 별 차이 없다.   
함수 호출과정에서 쓰이는 메모리가 더 있다고함 
