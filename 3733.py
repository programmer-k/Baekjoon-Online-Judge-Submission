#!/usr/bin/env python3

try:
    while True:
        inp = input()
        if inp == '':
            break
        inp = inp.split()
        n, s = int(inp[0]), int(inp[1])
        print(s // (n + 1))
except EOFError:
    pass
