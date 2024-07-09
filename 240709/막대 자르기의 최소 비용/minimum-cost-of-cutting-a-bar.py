n=int(input())
table=list(map(int,input().split()))
table.sort()
answer=0
길이=sum(table)
for i in range(n):
    길이-=table[i]
    answer+=길이*table[i]
print(answer)