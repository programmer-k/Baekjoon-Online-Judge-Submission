"""
파일 이름 : 6376.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : e의 근삿값을 구한다.
"""
from math import factorial, floor

def CalcE(n):
	""" e의 값을 근사한다. """
	e = 0
	for i in range(n + 1):
		e += 1 / factorial(i)
	
	# e가 int면, int로 형변환한다.
	if CheckIsInt(e):
		e = int(e)

	return e

def CheckIsInt(n):
	"""
		n이 int인지 float인지 판별한다.
		여기서는 소수점 자리가 모두 0이면 int로 간주한다.
	"""
	if n == floor(n):
		return True
	else:
		return False

def CheckNumLength(n):
	""" n의 소숫점 자리 수가 9보다 작으면 참을 반환한다. """
	if len(str(n).split('.')[1]) < 9:
		return True
	else:
		return False


# 결과 출력
print("n e")
print("- -----------")
for n in range(10):
	e = CalcE(n)
	if CheckIsInt(e):
		print(n, e)
	elif CheckNumLength(e):
		print(n, e)
	else:
		print(n, format(e, '.9f'))