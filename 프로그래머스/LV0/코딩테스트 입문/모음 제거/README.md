```python
import re
def solution(my_string):
    return re.sub('[a,e,i,o,u]', "", my_string)

def solution(my_string):
    return re.sub('a|e|i|o|u', "", my_string)

# [a,b,c,d ...] 또는 a|b|c|d ...

```