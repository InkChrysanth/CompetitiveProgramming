import sys
sys.set_int_max_str_digits(0)

m=int(input())
n=int(input())
l, r=0, 1

while r**m<=n:
    l=r
    r=r*2

while l+1<r:
    mid=(l+r)//2
    if mid**m<=n:
        l=mid
    else:
        r=mid

print(l)