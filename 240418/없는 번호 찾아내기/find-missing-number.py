numbers=[0 for _ in range(31)]
for _ in range(28):
    num=int(input())
    numbers[num]=1
for i in range(1,31):
    if(numbers[i]==0):
        print(i)