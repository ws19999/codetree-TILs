n,k=map(int,input().split())
if (k==1):
    for i in range(1,n+1):
        for j in range(n):
            print(i,end=' ')
        print()
elif (k==2):
    for i in range(1,n+1):
        if(i%2==1):
            for j in range(1,n+1):
                print(j,end=' ')
            print()
        else:
            for j in range(n,0,-1):
                print(j,end=' ')
            print()
else:
    for i in range(1,n+1):
        for j in range(1,n+1):
            print(i*j,end=' ')
        print()