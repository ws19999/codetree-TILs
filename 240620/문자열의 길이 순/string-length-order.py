strings=[[] for _ in range(31)]
n=int(input())
for _ in range(n):
    str=input()
    strings[len(str)].append(str)
for i in range(1,31):
    strings[i].sort()
    for str in strings[i]:
        print(str)