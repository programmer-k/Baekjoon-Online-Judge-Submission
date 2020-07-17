from math import gcd

tempList = input().split(':')

num1 = int(tempList[0])
num2 = int(tempList[1])

temp = gcd(num1, num2)

num1 //= temp
num2 //= temp

print(str(num1) + ":" + str(num2))