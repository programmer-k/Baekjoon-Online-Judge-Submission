"""
파일 이름 : 10995.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 기본 문자열 만들기
s = '*' * num
s = ' '.join(s)


# 출력
for i in range(num):
	if (i % 2 == 0):
		print(s)
	else:
		print(' ' + s)