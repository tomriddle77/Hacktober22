def greatest(a,b,c):
    temp=a
    if(b>temp):
        temp=b
    if(c>temp):
        temp=c

    return temp

a=int(input())
b=int(input())
c=int(input())

d=greatest(a,b,c)
print(f"the greatest of {a}, {b}, {c} is {d}")
