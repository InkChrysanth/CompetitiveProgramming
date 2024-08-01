import decimal
with decimal.localcontext() as ctx:
    ctx.prec = decimal.MAX_PREC
    ctx.Emax = decimal.MAX_EMAX
    ctx.Emin = decimal.MIN_EMIN
    
    a=decimal.Decimal(input())
    b=decimal.Decimal(input())

    print(a*b)