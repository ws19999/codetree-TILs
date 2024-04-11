ee=False
ea=False
str=input()
for i in range(0,len(str)-1):
    if(str[i]=='e'):
        if(str[i+1]=='e'):
            ee=True
        elif(str[i+1]=='a'):
            ea=True
if(ee):
    print('YES',end=' ')
else:
    print('NO',end=' ')
if(ea):
    print('YES')
else:
    print('NO')