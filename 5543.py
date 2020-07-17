"""
파일 이름 : 5543.py
제작자 : 정지운
제작 날짜 : 2017년 6월 22일
프로그램 용도 : 가장 싼 세트 메뉴의 가격을 출력한다.
"""

# 입력
burger = []
for i in range(3):
	burger.append(int(input()))

coke = int(input())
sprite = int(input())

# 계산
if coke <= sprite:
	cheapDrink = coke
else:
	cheapDrink = sprite

cheapBurger = min(burger)

# 출력
print(cheapBurger + cheapDrink - 50)