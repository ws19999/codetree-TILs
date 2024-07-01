N=int(input())
lists=[]
for _ in range(N):
    Day, Name, num=input().split()
    Day=int(Day)
    num=int(num)
    lists.append((Day,Name,num))
lists.sort()
Bessie=7
Elsie=7
Mildred=7
이전랭크=7
랭크=0
answer=0
for i in lists:
    if(i[1]=='Bessie'):
        Bessie+=i[2]
    elif(i[1]=='Elsie'):
        Elsie+=i[2]
    else:
        Mildred+=i[2]
    if Bessie>Elsie and Bessie>Mildred:
        랭크=1
    elif Elsie>Bessie and Elsie>Mildred:
        랭크=2
    elif Mildred>Bessie and Mildred>Elsie:
        랭크=3
    elif Bessie==Elsie and Elsie>Mildred:
        랭크=4
    elif Elsie==Mildred and Elsie>Bessie:
        랭크=5
    elif Bessie==Mildred and Bessie>Elsie:
        랭크=6
    else:
        랭크=7
    if(이전랭크!=랭크):
        이전랭크=랭크
        answer+=1
print(answer)