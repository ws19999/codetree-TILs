n=int(input())
finished=False
lists=[0 for _ in range(ord('z')-ord('a')+1)]
strings=list(input().split())
for a in strings:
    if(ord(a)>ord('z') or ord(a)<ord('a')):
        finished=True
        break
    lists[ord(a)-ord('a')]+=1
for i in range(ord('z')-ord('a')+1):
    if(lists[i]>0):
        print(f"{chr(i+ord('a'))} : {lists[i]}")