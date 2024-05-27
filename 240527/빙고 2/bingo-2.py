table=[list(map(int,input().split())) for _ in range(5)]
lists=list(map(int,input().split()))
check=[[(0,0),(0,1),(0,2),(0,3),(0,4)],[(1,0),(1,1),(1,2),(1,3),(1,4)],[(2,0),(2,1),(2,2),(2,3),(2,4)],[(3,0),(3,1),(3,2),(3,3),(3,4)],[(4,0),(4,1),(4,2),(4,3),(4,4)],[(0,0),(1,0),(2,0),(3,0),(4,0)],[(0,1),(1,1),(2,1),(3,1),(4,1)],[(0,2),(1,2),(2,2),(3,2),(4,2)],[(0,3),(1,3),(2,3),(3,3),(4,3)],[(0,4),(1,4),(2,4),(3,4),(4,4)],[(0,0),(1,1),(2,2),(3,3),(4,4)],[(0,4),(1,3),(2,2),(3,1),(4,0)]]
for i in range(25):
    num=lists[i]
    F=False
    for a in range(5):
        for b in range(5):
            if(table[a][b]==num):
                table[a][b]=0
                F=True
                break
        if(F):
            break
    if(i>=12):
        cnt=0
        for a in check:
            f=True
            for b in a:
                if(table[b[0]][b[1]]!=0):
                    f=False
                    break
            if(f):
                cnt+=1
        if(cnt==3):
            print(i+1)
            break