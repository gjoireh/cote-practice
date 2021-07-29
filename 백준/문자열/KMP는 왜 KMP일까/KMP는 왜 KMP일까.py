strings_separated_by_slash = input().split('-')
result = ""

for s in strings_separated_by_slash:
    result += s[0]
print(result)