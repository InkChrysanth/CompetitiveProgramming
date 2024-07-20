def nth_palindrome(n):
     if n <= 2:
         return n - 1
     sn = str(n)
     drop = len(sn) - 1
     if '11' <= sn <= '2':
         rev_index = -1
     else:
         rev_index = -2
         if sn < '2':
             drop -= 1
     sp = str(n - 10**drop)
     sp += sp[rev_index::-1]
     return int(sp)
n = int(input())
print(nth_palindrome(n))