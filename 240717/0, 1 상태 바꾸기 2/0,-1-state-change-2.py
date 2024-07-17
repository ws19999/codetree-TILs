from collections import deque
n=int(input())
lists=deque(map(int,input().split()))
lists.appendleft(0)
m=int(input())
for _ in range(m):
    type,num=map(int,input().split())
    if type==1:
        for i in range(num,n+1,num):
            if lists[i]==0:
                lists[i]=1
            elif lists[i]==1:
                lists[i]=0
    else:
        l=num
        r=num
        while l>0 and r<=n:
            if(lists[l]!=lists[r]):
                break
            if lists[l]==0:
                lists[l]=1
                lists[r]=1
            else:
                lists[l]=0
                lists[r]=0
            l-=1
            r+=1
for i in range(1,n+1):
    print(lists[i],end=' ')