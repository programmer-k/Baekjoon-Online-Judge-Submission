"""
파일 이름 : 2941.py
제작자 : 정지운
제작 날짜 : 2017년 10월 21일
"""

# 입력
s = input()

ans = 0

# 크로아티아 알파벳 개수 세기
while True:
	if s[0:2] in ("c=", "c-", "d-", "lj", "nj", "s=", "z="):
		ans += 1
		s = s[2:]
	elif s[0:3] == "dz=":
		ans += 1
		s = s[3:]
	else:
		ans += 1
		s = s[1:]

	# 탈출 조건
	if len(s) == 0:
		break

# 출력
print(ans)