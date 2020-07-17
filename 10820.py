"""
파일 이름 : 10820.py
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
"""

for i in range(100):
	# 입력
	s = input()

	# 탈출 조건
	if s == '':
		break

	# 대소문자, 숫자, 공백 수 검사
	upper = 0
	lower = 0
	digit = 0
	blank = 0

	for ch in s:
		if ch.isalpha():
			if ch.isupper():
				upper += 1
			else:
				lower += 1
		elif ch.isdigit():
			digit += 1
		else:
			blank += 1
	
	# 출력
	print(lower, upper, digit, blank)