"""
파일 이름 : 13163.py
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
"""

# tc 입력
tc = int(input())

# tc만큼 반복
for i in range(tc):
    # 입력
    tempList = input().split()

    # 변경
    tempList[0] = 'god'

    # 문자열로 변환
    ans = ''
    for s in tempList:
        ans += s

    # 출력
    print(ans)