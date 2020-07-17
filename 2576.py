"""
파일 이름 : 2576.py
제작자 : 정지운
제작 날짜 : 2018년 2월 14일
"""

lst = []
for i in range(7):
	lst.append(int(input()))

odd = []
for num in lst:
	if num % 2 == 1:
		odd.append(num)

if len(odd) == 0:
	print(-1)
else:
	print(sum(odd))
	print(min(odd))