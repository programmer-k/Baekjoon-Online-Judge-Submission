"""
파일 이름 : 5363.py
제작자 : 정지운
제작 날짜 : 2017년 8월 3일
"""

# 입력
tc = int(input())

for i in range(tc):
	# 입력
	tempList = input().split(' ')

	# 출력
	for j in range(2, len(tempList)):
		print(tempList[j], end = ' ')
	
	print(tempList[0], tempList[1])