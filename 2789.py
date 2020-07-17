"""
파일 이름 : 3789.py
제작자 : 정지운
제작 날짜 : 2017년 6월 19일
제작 목표 : 텍스트를 암호화한다.
"""

# 입력
s = input()

output = ''
# Cambridge에 포함된 알파벳을 지운다.
for ch in s:
	if ch in 'CAMBRIDGE':
		pass
	else:
		output += ch

# 출력
print(output)