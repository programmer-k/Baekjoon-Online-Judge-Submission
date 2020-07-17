"""
파일 이름 : 10826.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 15일
""

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
