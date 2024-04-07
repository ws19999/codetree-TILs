lists=[]
i=0
while True:
    a=input()
    if(a=="0"):
        break
    i+=1
    if(i%2==0):
        lists.append(a)
print(i)
for elem in lists:
    print(elem)