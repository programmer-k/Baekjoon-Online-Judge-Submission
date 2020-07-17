"""
파일 이름 : 2444.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력
for i in range(num):
	# 증가 부분
	print(' ' * (num - (i + 1)), end = '')
	print('*' * (i * 2 + 1))

for j in range(num - 1):
	# 감소 부분
	print(' ' * (j + 1), end = '')
	print('*' * (2 * (num - 1 - j) - 1))