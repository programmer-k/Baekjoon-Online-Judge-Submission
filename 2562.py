"""
파일 이름 : 2562.py
제작자 : 정지운
제작 날짜 : 2018년 2월 14일
"""

lst = []

for i in range(9):
	lst.append(int(input()))

print(max(lst))
print(lst.index(max(lst)) + 1)