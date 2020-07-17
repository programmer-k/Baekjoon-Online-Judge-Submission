"""
파일 이름 : 10992.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력
for i in range(num - 1):
	print(' ' * (num - 1 - i), end = '')
	
	# 첫 번째 줄에서는 별을 하나만 출력
	if i == 0:
		print('*')
		continue
	
	print('*', end = '')
	print(' ' * (2 * i - 1), end = '')
	print('*')

# 마지막 줄 출력
print('*' * (2 * num - 1))