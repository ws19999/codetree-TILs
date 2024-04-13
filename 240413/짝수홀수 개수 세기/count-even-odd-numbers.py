n=int(input())
odd=0
even=0
finished=False
for _ in range(n):
    num=int(input())
    if(finished==False):
        if(num==0):
            finished=True
        elif(num%2==0):
            even+=1
        elif(num%2==1):
            odd+=1
print(even)
print(odd)