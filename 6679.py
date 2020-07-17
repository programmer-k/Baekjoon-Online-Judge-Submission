"""
파일 이름 : 6679.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
제작 목표 : 싱기한 숫자를 구한다.
"""
def NumToAlpha(num):
	""" 숫자를 알파벳으로 변환한 후 반환한다. """
	if num == 10:
		return 'A'
	elif num == 11:
		return 'B'
	elif num == 12:
		return 'C'
	elif num == 13:
		return 'D'
	elif num == 14:
		return 'E'
	elif num == 15:
		return 'F'

def AlphaToNum(ch):
	""" 알파벳을 숫자로 변환한 후 반환한다. """
	if ch == 'A':
		return 10
	elif ch == 'B':
		return 11
	elif ch == 'C':
		return 12
	elif ch == 'D':
		return 13
	elif ch == 'E':
		return 14
	elif ch == 'F':
		return 15


def ConvTok(num, k):
	""" 10진수를 k진수로 변환해서 문자열로 반환한다. """
	s = ''
	for i in range(3, -1, -1):
		temp = num // (k ** i)

		# 숫자가 10보다 같거나 크면 한자리로 표현할 수 없으므로 알파벳으로 대신 표현한다.
		if temp >= 10:
			s += NumToAlpha(temp)
		else:
			s += str(temp)
		num %= (k ** i)
	
	return s

def AddAllNum(s):
	""" 각 자리 숫자의 합을 반환한다. """
	num = 0
	for ch in s:
		# 숫자가 알파벳이면 숫자로 변환한 후 더한다.
		if ch.isalpha():
			num += AlphaToNum(ch)
		else:
			num += int(ch)
	
	return num

# 1000부터 9999까지 숫자 중 싱기한 숫자를 찾는다.
for num in range(1000, 10000):
	# 12, 16진수로 변환
	twl = ConvTok(num, 12)
	hex = ConvTok(num, 16)

	# 각 자리 숫자의 합을 계산한다.
	ten_r = AddAllNum(str(num))
	twl_r = AddAllNum(twl)
	hex_r = AddAllNum(hex)
	
	# 싱기한 숫자인지 검사한다.
	if ten_r == twl_r and twl_r == hex_r:
		print(num)
