"""
파일 이름 : 2935.py
제작자 : 정지운
제작 날짜 : 2017년 7월 14일
프로그램 용도 : 단순 계산을 한다.
"""

# 입력
num1 = int(input())
operator = input()
num2 = int(input())

# 계산
if operator == '+':
	result = num1 + num2
else:
	result = num1 * num2

# 출력
print(result)