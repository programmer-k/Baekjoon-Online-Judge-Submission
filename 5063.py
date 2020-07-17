"""
파일 이름 : 5063.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 광고를 해야하는지 분석한다.
"""

# 입력
tc = int(input())

# tc의 수만큼 반복
for i in range(tc):
	# 입력
	strList = input().split(' ')
	
	noAdProfit = int(strList[0])
	adProfit = int(strList[1])
	adCost = int(strList[2])

	# 계산 및 출력
	if noAdProfit > adProfit - adCost:
		print("do not advertise")
	elif noAdProfit == adProfit - adCost:
		print("does not matter")
	else:
		print("advertise")