n,c=input().split()
n=int(n)
cnt=0
lists=[]
for _ in range(n):
    str=input()
    if(str[3]==c):
        lists.append(str)
        cnt+=1
print(cnt)
for i in range(cnt):
    print(lists[i])