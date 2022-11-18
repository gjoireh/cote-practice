정규표현식 : '\d+'
=> 하나 이상 연결된 숫자문자열

```python
re.findall('\d+', 문자열)
# 문자열에서 숫자를 모두 찾아줌
```

```python
sort(key=len)
sort(key=lambda x : x[1])
# sort key에 정렬 기준 함수 지정 가능
```