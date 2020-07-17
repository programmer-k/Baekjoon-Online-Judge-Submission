"""
파일 이름 : 9625.py
제작자 : 정지운
제작 날짜 : 2017년 6월 19일
제작 목표 : 규칙을 K번 반복할 때의 결과를 계산한다.
"""

# 입력
num = int(input())

# 초기값
numA = 1
numB = 0

# num의 크기만큼 반복
for i in range(num):
	# A의 개수와 B의 개수 계산

	# A 변환
	numA_r = 0
	numB_r = numA

	# B 변환
	numA_r = numB
	numB_r += numB

	# 결과 값을 초기값으로 설정
	numA = numA_r
	numB = numB_r

# 출력
print(numA, numB)