"""
파일 이름 : 3047.cpp
제작자 : 정지운
제작 날짜 : 2018년 6월 3일
"""

input_list = []

# 입력
lst = input().split()
for i in lst:
    input_list.append(int(i))

s = input()

# 정렬
input_list.sort()

# A, B, C에 값 할당하기
A = min(input_list)
C = max(input_list)
for num in input_list:
    if num > A and num < C:
        B = num
        break

# 출력
for ch in s:
    if ch == 'A':
        print(A, end=" ")
    elif ch == 'B':
        print(B, end=" ")
    else:
        print(C, end=" ")