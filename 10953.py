"""
파일 이름 : 10953.py
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : A + B를 출력한다.
"""

# 입력
tc = int(input())

for i in range(tc):
	# 입력
	tempList = input().split(',')
	
	# 계산
	num1 = int(tempList[0])
	num2 = int(tempList[1])

	# 출력
	print(num1 + num2)