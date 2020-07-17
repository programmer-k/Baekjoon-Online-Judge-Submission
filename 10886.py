"""
파일 이름 : 10886.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 설문조사를 분석한다.
"""

# 입력
voteNum = int(input())

agree = 0
disagree = 0

# voteNum의 수만큼 입력을 받는다.
for i in range(voteNum):
	vote = int(input())
	
	# 설문조사 분석
	if vote == 1:
		agree += 1
	else:
		disagree += 1

# 출력
if agree > disagree: # 설문조사한 사람의 수가 홀수이므로 agree와 disagree가 같은 경우는 없다.
	print("Junhee is cute!")
else:
	print("Junhee is not cute!")