"""
파일 이름 : 1181.py
제작자 : 정지운
제작 날짜 : 2018년 6월 5일
"""

# 정렬 함수
#def sort(word):
#    return len(word) +

lst = []
n = int(input())

for i in range(n):
    s = input()
    if s not in lst:
        lst.append(s)

lst.sort(key=lambda element : len(element))

for word in lst:
    print(word)