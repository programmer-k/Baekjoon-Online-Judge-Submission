"""
파일 이름 : 5565.py
제작자 : 정지운
제작 날짜 : 2017년 6월 22일
프로그램 용도 : 책의 가격을 구한다.
"""

# 입력
total = int(input())

book = []
for i in range(9):
	book.append(int(input()))

# 계산
answer = total - sum(book)

# 출력
print(answer)