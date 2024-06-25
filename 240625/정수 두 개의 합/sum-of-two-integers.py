n=int(input())
m=int(input())
lists=list(map(int,input().split()))
table=[0 for _ in range(100001)]
lists.sort()
for i in lists:
    table[i]+=1
j=n-1
i=0
ans=0
check=[0 for _ in range(100001)]
while(i<j):
    if(lists[i]==lists[j] and lists[i]+lists[j]==m):
        ans+=(table[lists[i]]*(table[lists[i]]-1))//2
        break
    if(lists[i]+lists[j]>m):
        j-=1
    elif(lists[i]+lists[j]<m):
        i+=1
    else:
        if(check[lists[i]]==0 and check[lists[j]]==0):
            check[lists[i]]=1
            check[lists[j]]=1
            ans+=table[lists[i]]*table[lists[j]]
            j-=1
        else:
            j-=1
print(ans)