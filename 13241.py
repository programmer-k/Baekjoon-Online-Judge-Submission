from math import gcd
inp = [eval(i) for i in input().split()]
print(inp[0] * inp[1] // gcd(*inp))