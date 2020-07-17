"""
파일 이름 : 4659.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 비밀번호의 품질을 평가한다.
"""

def VowelIn(s):
	""" 문자열에 모음이 있으면 True, 그렇지 않으면 False를 반환한다. """
	if ('a' in s) or ('e' in s) or ('i' in s) or ('o' in s) or ('u' in s):
		return True
	else:
		return False

def ContiVowCon(s):
	""" 문자열에 모음이나 자음이 연속으로 3개가 있으면 False를 반환한다. """
	for i in range(1, len(s) - 1):
		if (VowelIn(s[i - 1]) and VowelIn(s[i]) and VowelIn(s[i + 1])) or \
				not(VowelIn(s[i - 1]) or VowelIn(s[i]) or VowelIn(s[i + 1])):
			return False

	# 문자열의 길이가 3 미만일 경우 무조건 참이다.
	return True

def SameChar(s):
	""" 문자열에 같은 글자가 두 번 오면 False를 반환한다. 단 e와 o는 예외 """
	for i in range(len(s) - 1):
		if s[i] in ('e', 'o'): continue
		if s[i] == s[i + 1]:
			return False
	return True

# ------------------------ main -------------------------------

while True:
	s = input()

	# 탈출 조건 : 문자열이 end이다.
	if s == "end":
		break
	
	# 조건 검사 및 출력
	if VowelIn(s) and ContiVowCon(s) and SameChar(s):
		print('<' + s + '>', 'is acceptable.')
	else:
		print('<' + s + '>', 'is not acceptable.')