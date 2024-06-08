lists=list(input().split('-'))
ans=0
for i in range(len(lists)):
    num=0
    temp=list(lists[i].split('+'))
    for a in temp:
        num+=int(a)
    if(i==0):
        ans+=num
    else:
        ans-=num
print(ans)