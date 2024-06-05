str=input()
cnt=0
table=[0 for _ in range(len(str))]
lists=['a','b','c','d','e']
while(True):
    pos=False
    s=0
    temps=[]
    for i in range(len(str)):
        if(table[i]==1):
            continue
        if(str[i]==lists[s]):
            temps.append(i)
            s+=1
            if(s==5):
                pos=True
                for j in temps:
                    table[j]=1
                temps=[]
                s=0
    if(pos):
        cnt+=1
    else:
        break
if(cnt==0):
    print(-1)
else:
    print(cnt)