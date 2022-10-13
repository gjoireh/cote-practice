### 문제
***
[링크](https://school.programmers.co.kr/learn/courses/30/lessons/120882)

###
***
정렬 전 리스트와 정렬 후 리스트를 비교하여 순위를 확인할 수 있다  

enumerate 라는 것을 알게 되었다  
이것을 사용하면  

```python
dict1 = dict()
i = 1
for ss in sorted_score:
    if ss not in dict1:
        dict1[ss] = i
    i += 1
```
같은 것을

```python
dict1 = dict()
for i,ss in enumerate(sorted_score):
    if ss not in dict1:
        dict1[ss] = i + 1
```
같이 나타낼 수 있다  
