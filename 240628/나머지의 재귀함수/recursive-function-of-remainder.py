n=int(input())
def recursive(num):
    if(num==1):
        return 2
    elif(num==2):
        return 4
    else:
        return (recursive(num-1)*recursive(num-2))%100
print(recursive(n))