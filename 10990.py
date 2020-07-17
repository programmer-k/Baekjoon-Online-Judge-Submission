"""
파일 이름 : 10990.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력
for i in range(num):
	print(' ' * (num - (i + 1)), end = '')

	# i가 0이 아닐 때는 별 문자를 두 개 출력한다.
	if i != 0:
		print('*', end = '')
		print(' ' * (2 * i - 1), end = '')
	
	print('*')