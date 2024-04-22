n=int(input())
finished=False
lists=[0 for _ in range(ord('z')-ord('a'))]
strings=list(input().split())
for a in strings:
    if(ord(a)>ord('z') or ord(a)<ord('a')):
        finished=True
    if(not finished):
        lists[ord(a)-ord('a')]+=1
for i in range(ord('z')-ord('a')):
    if(lists[i]>0):
        print(f"{chr(i+ord('a'))} : {lists[i]}")