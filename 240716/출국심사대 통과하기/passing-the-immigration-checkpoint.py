N=int(input())
사람들=[]
for _ in range(N):
    도착시간,심사시간=map(int,input().split())
    사람들.append((도착시간,심사시간))
사람들.sort()
시간=0
for 사람 in 사람들:
    if 사람[0]<시간:
        시간+=사람[1]
    else:
        시간=사람[0]+사람[1]
print(시간)