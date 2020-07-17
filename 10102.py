"""
파일 이름 : 10102.py
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
"""

# 입력
input()
s = input()

# 계산
voteA = s.count('A')
voteB = s.count('B')

# 출력
if voteA > voteB:
	print('A')
elif voteA < voteB:
	print('B')
else:
	print("Tie")