"""
파일 이름 : 10707.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 싼 수도 요금을 구해서 출력한다.
"""

# 입력
xCostPer1L = int(input())
yBasicCost = int(input())
yThreshold = int(input())
yExtraCost = int(input())
waterUse = int(input())


# 계산

# X사의 요금 계산
xCost = xCostPer1L * waterUse

# Y사의 요금 계산
if waterUse <= yThreshold:
	# 상한선을 넘지 않아 기본 요금만 청구되는 경우
	yCost = yBasicCost
else:
	# 상한선을 넘어 추가 요금이 청구되는 경우
	yCost = yBasicCost + (waterUse - yThreshold) * yExtraCost


# 비교 및 출력
if xCost <= yCost:
	print(xCost)
else:
	print(yCost)