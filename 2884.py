"""
파일 이름 : 2884.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 알람 시간을 출력한다.
"""

# 입력
s = input()
hour = int(s.split(' ')[0])
min = int(s.split(' ')[1])

# 계산

# 분이 작은 경우 -> 시를 깎고 분을 늘린다.
if min - 45 < 0:
	hour -= 1
	min += 60
	
	# 시가 -1이면 전날 시로 바꾼다.
	if hour == -1:
		hour = 23

min -= 45

# 출력
print(hour, min)