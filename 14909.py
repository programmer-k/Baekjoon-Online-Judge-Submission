lst = input().split()

cnt = 0
for s in lst:
    if '-' not in s and s != '0':
        cnt += 1

print(cnt)