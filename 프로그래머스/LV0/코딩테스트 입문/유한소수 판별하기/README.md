### 문제
***
[링크](https://school.programmers.co.kr/learn/courses/30/lessons/120878)

### 풀이
***

다른 사람의 풀이를 보다가 좋은 풀이들을 봤다      

```python
def solution(a, b):
    return 1 if a/b * 1000 % 1 == 0 else 2
```  
a/b의 분모에 2,5이외의 소인수가 없다면 a/b*1000은 정수일 것이다   
연산 결과에 약분이 포함된 것이므로 기약분수로 만드는 과정은 필요 없다   

```python
from math import gcd
def solution(a, b):
    b //= gcd(a,b)
    while b%2==0:
        b//=2
    while b%5==0:
        b//=5
    return 1 if b==1 else 2
``` 

기약분수로 만든 후 분모에서 2,5 성분을 모두 제거하여 다른 소인수가 있는지 확인하고 있다  
