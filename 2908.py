"""
파일 이름 : 2908.py
제작자 : 정지운
제작 날짜 : 2017년 7월 23일
프로그램 용도 : 상수의 답을 출력한다.
"""

# 입력
tempList = input().split(' ')
num1 = tempList[0]
num2 = tempList[1]

# 숫자 거꾸로 읽기
num1 = int(num1[2] + num1[1] + num1[0])
num2 = int(num2[2] + num2[1] + num2[0])

# 숫자 비교 및 출력
if num1 > num2:
	print(num1)
else:
	print(num2)