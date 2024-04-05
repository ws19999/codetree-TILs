n=int(input())
lists=[]
for _ in range(n):
    str=input()
    lists.append(str)
for str in lists:
    for c in range(len(str)-1,-1,-1):
        print(str[c],end='')
    print()