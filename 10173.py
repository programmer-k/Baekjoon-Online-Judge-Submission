"""
파일 이름 : 10173.py
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
"""

while (True):
	# 입력
	s = input()

	# 탈출 조건
	if s == "EOI":
		break
	
	# nemo가 있는지 검사
	s = s.lower()
	num = s.find("nemo")

	# 출력
	if num == -1:
		print("Missing")
	else:
		print("Found")