"""
파일 이름 : 2822.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 점수를 계산한다.
"""

# 입력
scores = []
for i in range(8):
	scores.append(int(input()))

# 가장 높은 점수 5개만 빼낸다.
idxs = [] # 인덱스 값 저장
highest = [] # 점수 저장
for i in range(5):
	highest.append(max(scores))
	idxs.append(scores.index(highest[i]) + 1)
	scores[scores.index(highest[i])] = 0

# 인덱스 값을 순서대로 나열한다.
idxs.sort()

# 출력
print(sum(highest))
for i in range(5):
	print(idxs[i], end = ' ')