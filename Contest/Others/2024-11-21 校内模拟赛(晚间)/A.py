import decimal
with decimal.localcontext() as ctx:
    ctx.prec = decimal.MAX_PREC
    ctx.Emax = decimal.MAX_EMAX
    ctx.Emin = decimal.MIN_EMIN
    
    n=decimal.Decimal(input())
    l, r=decimal.Decimal(1), decimal.Decimal(50000)
    while l+1<r:
        mid=decimal.Decimal((l+r)//2)
        if mid**mid<=n:
            l=mid
        else:
            r=mid
    print(l) # it must work
# import sys
# sys.set_int_max_str_digits(0)

# n=int(input())
# l, r=0, 50000
# while l+1<r:
#     mid=(l+r)//2
#     if mid**mid<=n:
#         l=mid
#     else:
#         r=mid
# print(l) # maybe it works?