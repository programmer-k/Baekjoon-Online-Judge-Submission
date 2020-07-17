"""
파일 이름 : 11444.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 15일
"""

# 시간 초과
# 애초에 반복문이 최대 90경인가 900경 반복하는데 시간 초과가 안 날리 없음.

num = int(input())

f1, f2 = 0, 1
f3 = -1

if num == 0 or num == 1:
    print(num)
else:
    for i in range(1, num):
        f3 = f1 + f2
        f1 = f2
        f2 = f3

    # print(f3 % 1000000007)
    print(f3)
