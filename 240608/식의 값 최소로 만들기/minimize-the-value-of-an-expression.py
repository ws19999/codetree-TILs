line=list(input().split('-'))
ans=0
for item in range(len(line)):
    num=0
    temp=list(line[item].split('+'))
    for a in temp:
        num+=int(a)
    if(item==0):
        ans+=num
    else:
        ans-=num
print(ans)