"""
파일 이름 : 10798.py
제작자 : 정지운
제작 날짜 : 2017년 6월 22일
프로그램 용도 : 문자열을 세로로 읽어 출력한다.
"""

# 입력
strList = []
for i in range(5):
	strList.append(input())

# 출력
for j in range(15):
	for i in range(5):
		# IndexError가 발생하더라도 무시하고 넘어간다.
		try:
			print(strList[i][j], end = '')
		except IndexError:
			pass