"""
파일 이름 : 1769.py
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
"""

"""시간 초과로 인한 문제 풀이 실패 """

# 입력
num = int(input())
sum = 0
cnt = 0

# 한 자리수의 경우에는 연산하지 않고 바로 출력
if (num >= 10):
    while True:
        sum = 0

        # 각 자리의 숫자 합 구하기
        s = str(num)

        for ch in s:
            sum += int(ch)

        # 한 번 반복했으므로 증가
        cnt += 1

        # 한 자리수면 반복 종료
        if sum < 10:
            break

        num = sum
else:
    sum = num

# 반복을 몇 번 했는지 출력
print(cnt)

# 3의 배수인지 검사
if sum % 3 == 0:
    print('YES')
else:
    print('NO')
