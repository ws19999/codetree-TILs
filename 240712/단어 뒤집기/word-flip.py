from collections import deque
import sys
str=sys.stdin.readline()
rev=True
temp=deque()
for i in range(0,len(str)):
    if not rev:
        print(str[i],end='')
        if(str[i]=='>'):
            rev=True
    elif(str[i]==' '):
        for j in temp:
            print(j,end='')
        temp.clear()
        print(' ',end='')
    elif(str[i]=='<'):
        for j in temp:
            print(j,end='')
        temp.clear()
        print('<',end='')
        rev=False
    else:
        temp.appendleft(str[i])
if temp:
    for j in temp:
        print(j,end='')