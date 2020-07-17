lst = []

tc = int(input())

tempList = input().split()

for i in range(len(tempList)):
    tempList[i] = int(tempList[i])

tempList.remove(max(tempList))

print(sum(tempList))