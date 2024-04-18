a,b,c=map(int,input().split())
lists=[a,b,c,a*b,b*c,c*a,a*b*c]
lists.sort()
ans=0
if(a%2==0 and b%2==0 and c%2==0):
    print(lists[-1])
else:
    for elem in lists:
        if(elem%2==1):
            ans=elem
    print(ans)