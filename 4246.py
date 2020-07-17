"""
파일 이름 : 4246.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 암호화된 문자열을 복호화한다.
"""

while True:
	# 입력
	column = int(input())

	# 탈출 조건 : 0 입력
	if column == 0:
		break

	s = input()
	

	lst = []
	# 리스트 초기화
	for i in range(len(s) // column):
		lst.append([])
		for j in range(column):
			lst[i].append(0)
	

	i = -1
	j = -1
	idx = 0
	# 문자열을 리스트의 형태로 저장한다.
	while (i != len(lst) - 1):
		# 각 while문을 돌릴 때마다 값들을 약간씩 수정해줘야 한다.
		k = 0
		i += 1
		j += 1
		# 오른쪽 방향
		while k < column:
			lst[i][j] = s[idx]
			j += 1
			idx += 1
			k += 1
		
		# 탈출 조건 검사 : i, j가 마지막 element인가?
		if i == len(lst) - 1 and j == len(lst[i]):
			break
		else:
			j -= 1
			i += 1

		k = 0
		# 왼쪽 방향
		while k < column:
			lst[i][j] = s[idx]
			j -= 1
			idx += 1
			k += 1

	# 문자열 출력
	for j in range(column):
		for i in range(len(lst)):
			print(lst[i][j], end = '')
	print()
