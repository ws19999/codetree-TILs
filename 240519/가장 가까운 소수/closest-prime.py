n=int(input())
if(n==1):
    n+=1
차이=0
while(True):
    f=False
    prime=True
    for i in range(2,n-차이):
        if((n-차이)%i==0):
            prime=False
            break
    if(prime):
        f=True
        print(n-차이,end=' ')
    prime=True
    if(차이>0):
        for i in range(2,n+차이):
            if((n+차이)%i==0):
                prime=False
                break
        if(prime):
            f=True
            print(n+차이)
    if(f):
        break
    차이+=1