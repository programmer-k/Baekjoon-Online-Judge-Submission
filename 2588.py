"""
파일 이름 : 2588.py
제작자 : 정지운
제작 날짜 : 2017년 7월 26일
프로그램 용도 : 곱하기의 과정을 출력한다.
"""

# 입력
num1 = int(input())
num2 = int(input())

# 계산 및 출력
num3 = num2

while num2 != 0:	# 맨 뒤의 수부터 차례차례 곱해서 출력한다.
	print(num1 * (num2 % 10))
	num2 //= 10

print(num1 * num3)