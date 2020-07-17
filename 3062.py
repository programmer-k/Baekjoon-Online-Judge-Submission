"""
파일 이름 : 3062.py
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
"""

# tc 입력
tc = int(input())

# tc만큼 반복
for i in range(tc):
    # 입력
    s1 = input()

    # 숫자 뒤집기
    s2 = ''
    for j in range(len(s1) - 1, -1, -1):
        s2 += s1[j]

    # 합계 구하기
    num = int(s1) + int(s2)

    # 숫자가 좌우 대칭인지 검사하기
    s = str(num)

    is_palindrome = True
    for j in range(0, len(s) // 2):
        if s[j] != s[len(s) - 1 - j]:
            is_palindrome = False
            break

    # 출력
    if is_palindrome:
        print('YES')
    else:
        print('NO')