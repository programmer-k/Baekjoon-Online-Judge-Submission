"""
파일 이름 : 2522.py
제작자 : 정지운
제작 날짜 : 2017년 7월 27일
프로그램 용도 : 별을 출력한다.
"""

# 입력
num = int(input())

# 반복문을 이용하여 별을 출력한다.
# 증가 부분
for j in range(num):
	print(format('*' * (j + 1), '>' + str(num)))

# 감소 부분
for j in range(num - 1, 0, -1):
	print(format('*' * j, '>' + str(num)))