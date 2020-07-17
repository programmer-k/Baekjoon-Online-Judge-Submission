"""
파일 이름 : 3474.py
제작자 : 정지운
제작 날짜 : 2017년 6월 19일
프로그램 용도 : N!의 오른쪽 끝에 있는 0의 개수를 출력한다.
"""

# 이 문제는 factorial 함수를 사용할 때, 시간이 너무 오래 걸려 시간초과로 인해 정답을 맞추지 못하였습니다.

from math import factorial

# 입력
num = int(input())

# num만큼 반복
for i in range(num):
	# 입력
	n = int(input())

	# 펙토리얼 계산
	result = str(factorial(n))
	
	ans = 0
	# 오른쪽에 있는 0의 개수 계산
	for j in range(len(result) - 1, -1, -1):
		if result[j] == '0':
			ans += 1
		else:
			break
	
	# 출력
	print(ans)
