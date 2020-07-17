"""
파일 이름 : 1159.py
제작자 : 정지운
제작 날짜 : 2017년 6월 19일
제작 목표 : 문자열을 처리한다.
"""

# 입력
numOfPerson = int(input())

nameList = []
for i in range(numOfPerson):
	nameList.append(input())

# 성의 첫 글자가 같은 사람이 5명 있는지 조사한다.
giveUp = True
alpha = ord('a')
# 모든 소문자 알파벳 조사
while alpha <= ord('z'):
	sameName = 0
	for i in range(numOfPerson):
		if chr(alpha) == nameList[i][0]:
			sameName += 1
		
		# 5명을 찾으면 반복 종료하고 다음 알파벳으로 넘어간다.
		if sameName == 5:
			print(chr(alpha), end = '')
			giveUp = False
			break
		
	alpha += 1

# 5명을 한 번도 못찾았으면 "PREDAJA" 출력
if giveUp:
	print("PREDAJA")