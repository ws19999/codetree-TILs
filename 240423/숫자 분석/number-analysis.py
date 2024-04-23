num=int(input())
cnt=0
while(num>0):
    print(num%10,end='')
    cnt+=num%10
    num=num//10
print(f' {cnt}')