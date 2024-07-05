sets={""}
n,m=map(int,input().split())
정답=0
for _ in range(n):
    str=input()
    sets.add(str)
for _ in range(m):
    str=input()
    if str in sets:
        정답+=1
print(정답)