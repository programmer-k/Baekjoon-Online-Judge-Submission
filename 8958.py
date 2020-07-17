"""
파일 이름 : 8958.py
제작자 : 정지운
제작 날짜 : 2017년 10월 21일
"""

# tc 입력
tc = int(input())

# tc 만큼 반복
for i in range(tc):
	# 변수 초기화
	score = 0
	scoreSum = 0

	# 문자열 입력
	s = input()

	# 계산
	for ch in s:
		if ch == 'O':
			score += 1
			scoreSum += score
		elif ch == 'X':
			score = 0

	# 출력
	print(scoreSum)