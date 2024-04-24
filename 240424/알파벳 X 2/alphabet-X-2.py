lists=[[] for _ in range(26)]
str=input()
for i in range(52):
    lists[ord(str[i])-ord('A')].append(i)
cnt=0
for i in range(26):
    for j in range(i+1,26):
        if((lists[i][0]<lists[j][0] and lists[i][1]<lists[j][1] and lists[i][1]>lists[j][0]) or (lists[i][0]>lists[j][0] and lists[i][1]>lists[j][1] and lists[i][0]<lists[j][1])):
            cnt+=1
print(cnt)