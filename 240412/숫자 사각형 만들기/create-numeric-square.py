n=int(input())
for i in range(9,9-n,-1):
    for j in range(i,i-n,-1):
        if(j<=1):
            print(1,end=' ')
        else:
            print(j,end=' ')
    print()