"""
파일 이름 : 11091.py
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 문자열이 팬그램인지 판별한다.
"""

# 입력
tc = int(input())

# tc의 수만큼 반복
for i in range(tc):
	# 입력
	s = input().lower()

	alphaUse = {}

	# 각 알파벳의 사용여부를 판별한다.
	ch = 'a'
	for j in range(26):
		# 문자가 있다면 True 없다면 False.
		if s.find(ch) == -1:
			alphaUse[ch] = False
		else:
			alphaUse[ch] = True
		
		# 다음 알파벳으로 ch를 설정한다.
		ch = chr(ord(ch) + 1)
	
	# 사용되지 않은 알파벳을 따로 저장한다.
	ch = 'a'
	missing = ''
	for j in range(26):
		if alphaUse[ch]:
			pass
		else:
			missing += ch
		
		# 다음 알파벳으로 ch를 설정한다.
		ch = chr(ord(ch) + 1)
	
	# 결과 출력
	if missing == '':
		print("pangram")	# missing이 빈 문자열이다 -> alphaUse에 False인 요소가 없다 -> 모든 알파벳이 사용되었다.(pangram)
	else:
		print("missing", missing)