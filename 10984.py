"""
파일 이름 : 10984.py
제작자 : 정지운
제작 날짜 : 2017년 6월 25일
프로그램 용도 : 학점을 구한다.
"""

# 입력
tc = int(input())

# tc의 수만큼 반복
for i in range(tc):
	# 입력
	classes = int(input())
	
	credit = 0
	GPASum = 0

	# classes의 수만큼 반복
	for j in range(classes):
		# 입력
		strList = input().split(' ')
		
		# 계산
		credit += int(strList[0])
		GPASum += int(strList[0]) * float(strList[1])
	
	# 출력
	print(credit, format(GPASum / credit, '.1f'))