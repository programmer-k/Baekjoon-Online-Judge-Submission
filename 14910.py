inp = [eval(i) for i in input().split()]

lst = list(inp)
lst.sort()

sort = True
for i in range(len(lst)):
    if lst[i] == inp[i]:
        pass
    else:
        sort = False

if sort:
    print("Good")
else:
    print("Bad")