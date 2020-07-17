"""
파일 이름 : 5622.py
제작자 : 정지운
제작 날짜 : 2017년 10월 21일
"""

# 입력
s = input()

time = 0
for ch in s:
	if ch in "ABC":
		time += 3
	elif ch in "DEF":
		time += 4
	elif ch in "GHI":
		time += 5
	elif ch in "JKL":
		time += 6
	elif ch in "MNO":
		time += 7
	elif ch in "PQRS":
		time += 8
	elif ch in "TUV":
		time += 9
	elif ch in "WXYZ":
		time += 10

# 출력
print(time)