import sys

def dfs(m, n):
    if m == 0:
        return
    r = m % 2
    m = m // 2
    dfs(m, n + 1)
    if m != 0 and r != 0:
        print("+", end="")
    if r == 1:
        if n == 0:
            print("2(0)", end="")
        elif n == 1:
            print("2", end="")
        elif n == 2:
            print("2(2)", end="")
        else:
            print("2(", end="")
            dfs(n, 0)
            print(")", end="")

with open('pow.in', 'r') as input_file, open('pow.out', 'w') as output_file:
    num = int(input_file.read().strip())
    sys.stdout = output_file
    dfs(num, 0)