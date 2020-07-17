n = int(input())

lst = [1, 2, 3]
for i in range(n):
    idx1, idx2 = [lst.index(eval(ch)) for ch in input().split()]
    temp = lst[idx1]
    lst[idx1] = lst[idx2]
    lst[idx2] = temp

print(lst[0])