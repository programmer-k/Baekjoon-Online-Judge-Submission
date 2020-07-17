"""
파일 이름 : 1316.py
제작자 : 정지운
제작 날짜 : 2017년 10월 21일
"""

# 그룹 단어인지 체크하는 함수이다.
def CheckGroupWord():
	# 문자열 입력
	s = input()

	for i in range(len(s) - 1):
		# 같은 문자가 하나도 없을 때
		idx = s[i + 1:].find(s[i])
		if idx == -1:
			continue
		# 같은 문자가 바로 그 다음 문자일 때
		elif idx == 0:
			continue
		# 그 외의 경우
		else:
			return False
	
	return True


# ------------------------------main--------------------------------

# tc 입력
tc = int(input())

ans = 0

# tc만큼 반복
for i in range(tc):
	check = CheckGroupWord()
	if check:
		ans += 1

# 출력
print(ans)