"""
파일 이름 : 1427.py
제작자 : 정지운
제작 날짜 : 2018년 6월 3일
"""

num = input()

lst = []
for ch in num:
    lst.append(int(ch))

lst.sort()
lst.reverse()
for n in lst:
    print(n, end="")