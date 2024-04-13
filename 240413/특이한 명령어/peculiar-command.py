n=int(input())
for _ in range(n):
    a,b,c=input().split()
    if(c=='s'):
        print(int(a)*int(b))
    elif (c=='t'):
        print(f'{int(a)*int(b)/2:.1f}')