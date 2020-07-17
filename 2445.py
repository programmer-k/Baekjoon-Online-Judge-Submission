"""
파일 이름 : 2445.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력

# 증가 부분
for i in range(num - 1):
	print('*' * (i + 1), end = '')
	print(' ' * (num * 2 - (i + 1) * 2), end = '')
	print('*' * (i + 1))

# 제일 긴 부분
print('*' * (num * 2))

# 감소 부분, 증가 부분의 반대순으로 range함수 구성
for i in range(num - 2, -1, -1):
	print('*' * (i + 1), end = '')
	print(' ' * (num * 2 - (i + 1) * 2), end = '')
	print('*' * (i + 1))