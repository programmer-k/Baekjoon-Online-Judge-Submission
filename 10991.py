"""
파일 이름 : 10991.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력
for i in range(num):
	print(' ' * (num - (i + 1)), end = '')

	# 별 출력
	s = ''
	while len(s) != (2 * i):
		s += "* "
	
	print(s + '*')