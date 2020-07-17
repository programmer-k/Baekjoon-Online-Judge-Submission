"""
파일 이름 : 1100.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 체스판의 하얀 칸 위에 말이 몇 개 있는지 출력한다.
"""

# 입력
inputLst = []
for i in range(8):
	inputLst.append(input())

# 계산
num = 0
for i in range(len(inputLst)):
	for j in range(len(inputLst[i])):
		# 인덱스 값의 합이 짝수이면 하얀 칸이라는 것을 이용한다.
		if ((i + j) % 2 == 0) and inputLst[i][j] == 'F':
			num += 1

# 결과 출력
print(num)