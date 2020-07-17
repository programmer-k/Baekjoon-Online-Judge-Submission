"""
파일 이름 : 4641.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 리스트 중 정확히 두 배가 되는 수가 몇 개 있는지 계산한다.
"""

while True:
	# 입력
	s = input()
	
	# 탈출 조건 : -1 입력
	if s == '-1':
		break

	# 리스트에 입력한 값을 저장한다.
	lst = s.split()
	for i in range(len(lst)):
		lst[i] = int(lst[i])
	
	num = 0
	# 두 배가 되는 수가 몇 개인지 계산한다.
	for i in range(len(lst)):
		for j in range(i + 1, len(lst)):
			if lst[i] * 2 == lst[j]:
				num += 1
			if lst[i] == lst[j] * 2:
				num += 1

	# 결과 출력
	print(num)