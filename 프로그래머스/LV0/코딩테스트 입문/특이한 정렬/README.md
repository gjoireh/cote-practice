### 문제
***
[링크](https://school.programmers.co.kr/learn/courses/30/lessons/120880)

###
***
sort 함수에 key 인자가 있고 여기에 함수를 넣어서 정렬 기준 같은 것을 설정할 수 있다는 것을 알게 됐다  
  
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
sort(key = lambda x : abs(n-x))
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
abs(n-x)값이 같은 것들에 대하여 두번째 기준으로 정렬해 준다  

</br>

***

</br>

C에서도 동일한 것을 할 수 있다  

qsor의 compare  
```C
int compare(const void* p1, const void* p2)
{
    return *p1 - *p2; // 오름차순
}
int compare(const void* p1, const void* p2)
{
    return *p2 - *p1; // 내림차순
}
```

그러므로 이 문제 같으면  
```c
struct nd
{
    int number;
    int distance;
}typedef ND;

int compare(const ND* arg1, const ND* arg2)
{
    // 1순위 정렬 조건
    if (arg1->distance != arg2->distance)
        return (arg1->distance - arg2->distance);
    // 2순위 정렬 조건
    return (arg2->number - arg1->number);
}

```
compare를 위와 같이 설정하여 ND 배열을 ND의 distance 값 기준으로 오름차순 정렬 하고  
ND의 distance가 같은 것에 대하여 ND배열을 ND의 number 값 기준으로 내림차순 정렬할 수 있다   

