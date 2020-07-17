"""
파일 이름 : 2750.py
제작자 : 정지운
제작 날짜 : 2017년 8월 3일
"""

lst = []

# 입력
tc = int(input())

for i in range(tc):
	lst.append(int(input()))

# 정렬
lst.sort()

# 출력
for i in range(tc):
	print(lst[i])