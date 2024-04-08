n=int(input())
m=int(input())
d=0
digit=1
while (m>0):
    num=n*(m%10)
    print(num)
    d+=digit*num
    m//=10
    digit*=10
print(d)