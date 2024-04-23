a=int(input())
b=int(input())
c=int(input())
lists=[0 for _ in range(10)]
num=a*b*c
while(num>0):
    lists[num%10]+=1
    num=num//10
for i in range(10):
    print(lists[i])