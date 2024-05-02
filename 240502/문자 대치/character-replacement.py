str=input()
pos=0
ans=""
lens=len(str)
while(True):
    if(pos>=lens):
        break
    if(str[pos]=='.'):
        ans+='.'
        pos+=1
    if(pos+3<lens):
        if(str[pos]=='X' and str[pos+1]=='X' and str[pos+2]=='X' and str[pos+3]=='X'):
            ans+='aaaa'
            pos+=4
        elif(str[pos]=='X' and str[pos+1]=='X'):
            ans+='bb'
            pos+=2
        else:
            ans='-1'
            break
    elif(pos+1<lens):
        if(str[pos]=='X' and str[pos+1]=='X'):
            ans+='bb'
            pos+=2
        else:
            ans='-1'
            break
    else:
        ans='-1'
        break
print(ans)