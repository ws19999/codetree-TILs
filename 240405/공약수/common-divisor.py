n=int(input())
lists=list(map(int,input().split()))
for i in range(1,min(lists)+1):
    if all(number%i==0 for number in lists):
        print(i)