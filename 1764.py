"""
파일 이름 : 1764.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 듣도 보도 못한 사람의 명단을 출력한다.
"""

# 시간 초과

# 입력
l = input().split(' ')
tc1 = int(l[0])
tc2 = int(l[1])

# 듣도 못한 사람의 이름을 리스트에 저장한다.
notHearList = []
for i in range(tc1):
	notHearList.append(input())


# 듣보잡의 수와 명단을 계산한다.
notHearNotSeeNum = 0
notHearNotSeeList = []
for i in range(tc2):
	notSeeName = input()
	# 보도 못한 사람이 듣도 못한 사람의 리스트에 있는지 검사한다.
	if notSeeName in notHearList:
		notHearNotSeeNum += 1
		notHearNotSeeList.append(notSeeName)

notHearNotSeeList.sort() # 사전순으로 정렬

# 출력
print(notHearNotSeeNum)
for i in range(len(notHearNotSeeList)):
	print(notHearNotSeeList[i])