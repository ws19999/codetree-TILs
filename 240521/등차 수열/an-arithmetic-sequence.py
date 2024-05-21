n,a,d=map(int,input().split())
p=a-d
lists=list(map(int,input().split()))
for i in lists:
    if(p+d==i):
        p+=d
if(p>=a):
    print((p-a)//d+1)
else:
    print(0)