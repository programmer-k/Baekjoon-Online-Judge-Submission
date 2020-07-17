"""
파일 이름 : 7600.py
제작자 : 정지운
제작 날짜 : 2017년 10월 21일
"""



while True:
	ans = 0

	# 입력
	s = input()

	# 탈출 조건
	if s == '#':
		break

	# 소문자로 바꾸기
	s = s.lower()
	
	# 알파벳 종류 개수 알아내기
	for num in range(97, 123):
		ch = chr(num)

		if s.find(ch) != -1:
			ans += 1
	
	# 출력
	print(ans)