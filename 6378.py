"""
파일 이름 : 6378.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
제작 목표 : 디지털 루트를 구한다.
"""

while True:
	s = input()

	# 입력받은 문자열이 0이면 프로그램 종료
	if s == '0':
		break

	# 디지털 루트 계산
	while True:
		num = 0
		for ch in s:
			num += int(ch)

		# num이 한 자리 수가 나올 때까지 반복
		if num < 10:
			print(num)
			break
		
		s = str(num)