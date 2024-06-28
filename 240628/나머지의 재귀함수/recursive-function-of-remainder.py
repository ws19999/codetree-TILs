n=int(input())
table=[-1 for _ in range(101)]
def recursive(num):
    if(num==1 or num==2):
        table[1]=2
        table[2]=4
        return
    recursive(num-1)
    table[num]=(table[num-2]*table[num-1])%100
recursive(n)
print(table[n])