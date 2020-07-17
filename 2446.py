"""
파일 이름 : 2446.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 출력

# 감소 부분
for i in range(num - 1):
	print(' ' * i, end = '')
	print('*' * ((2 * num - 1) - (2 * i)))

# 중간 부분
print(' ' * (num - 1), end = '')
print('*')

# 증가 부분, 감소 부분의 range 함수를 반대로 구성
for i in range(num - 2, -1, -1):
	print(' ' * i, end = '')
	print('*' * ((2 * num - 1) - (2 * i)))