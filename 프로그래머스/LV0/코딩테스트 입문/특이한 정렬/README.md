### 문제
***
[링크](https://school.programmers.co.kr/learn/courses/30/lessons/120880)

###
***
sort 또는 sorted함수에 key 인자가 있고 여기에 함수를 넣어서  
정렬 기준 같은 것을 설정할 수 있다는 것을 알게 됐다 
  
</br>

```python
def func(x):
    return -x

s = [1,2,3,4,5]  
s.sort(key=func)
print(s) # [5,4,3,2,1]
```
를 하면 s의 원소들은 각 요소의 -값을 기준으로 정렬된다  
그래서 [5,4,3,2,1] 이 된다  


그리고  
```python
def func(x)
    return -x
````
를  
```python
lambda x : -x
```
와 같이 나타낼 수 있다  

</br>

문제 조건에서 numlist의 각 원소는 n으로부터 떨어진 거리를 기준으로 정렬되어야 한다  
```python
리스트.sort(key = lambda x : abs(n-x))
or
sorted(리스트, key = lambda x : abs(n-x))
```
와 같이 n으로부터의 거리를 기준으로 정렬할 수 있다  

그런데 거리가 같다면 큰 수가 앞으로 와야 한다는 또 다른 정렬 조건이 있다  

</br>
</br>

```python
sort(key = lambda x : (abs(n-x), -x))
```
람다에서 위와 같이  
* 첫번째 정렬 기준 : abs(n-x)  
* 두번째 정렬 기준 :  x * -1    

() 속에 ,로 정렬 조건을 여러개 넣을 수 있다  

이렇게 하면 abs(n-x)를 기준으로 정렬한 후  
첫번째 정렬 기준을 유지하면서 두번째 조건을 기준으로 정렬해 준다  

이것을 통해 '거리가 같을 때는 큰 값을 앞으로 배치한다'  
를 해결할 수 있다  

