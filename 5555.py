"""
파일 이름 : 5555.py
제작자 : 정지운
제작 날짜 : 2017년 8월 2일
"""

# 입력
s = input()
tc = int(input())

# 계산
num = 0
for i in range(tc):
	# 문자열 s가 포함되어 있는지 검사
	idx = (input() * 2).find(s)

	if idx != -1:
		num += 1

# 출력
print(num)