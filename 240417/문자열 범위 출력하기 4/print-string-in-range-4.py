n=int(input())
str=input()
if(len(str)<=n):
    print(str)
else:
    for i in range(n):
        print(str[i],end='')