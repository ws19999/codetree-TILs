n=int(input())
lists=[]
for _ in range(n):
    str=input()
    lists.append(str)
lists.sort()
print(lists[0])