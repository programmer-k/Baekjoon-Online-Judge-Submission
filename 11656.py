"""
파일 이름 : 11656.py
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
"""

# 입력
s = input()

# 모든 접미사 리스트에 등록
lst = []
for i in range(len(s)):
	lst.append(s[i:len(s)])

# 정렬 후 출력
lst.sort()
for i in range(len(lst)):
	print(lst[i])