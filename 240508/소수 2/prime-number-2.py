n=int(input())
정답=0
리스트=[0 for _ in range(n+1)]
for i in range(2,n+1):
    if(리스트[i]==0):
        리스트[i]=1
        정답+=1
        temp=i
        while(True):
            temp+=i
            if(temp>n):
                break
            리스트[temp]=1
print(정답)