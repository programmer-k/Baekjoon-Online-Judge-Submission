"""
파일 이름 : 5355.py
제작자 : 정지운
제작 날짜 : 2017년 7월 26일
"""

# 입력
tc = int(input())

# tc의 수만큼 반복
for i in range(tc):
	# 입력
	tempList = input().split(' ')
	
	num = float(tempList[0])

	# 연산자 계산
	for j in range(1, len(tempList)):
		if tempList[j] == '@':
			num *= 3
		elif tempList[j] == '#':
			num -= 7
		elif tempList[j] == '%':
			num += 5
	
	# 출력
	print(format(num, '.2f'))