secret=dict()
str=input()
keys=input()
for i in range(ord('z')-ord('a')+1):
    secret[keys[i]]=chr(i+ord('a'))
secret[' ']=' '
for elem in str:
    print(secret[elem],end='')