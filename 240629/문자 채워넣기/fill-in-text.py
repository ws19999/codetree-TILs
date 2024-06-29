n=int(input())
str=list(input().split())
a=0
b=0
if(str[0]=='a'):
    a+=1
else:
    b+=1
for i in range(1,len(str)):
    if(str[i]!=str[i-1]):
        if(str[i]=='a'):
            a+=1
        else:
            b+=1
print(1+min(a,b))