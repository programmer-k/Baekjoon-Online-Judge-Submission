"""
파일 이름 : 10828.py
제작자 : 정지운
제작 날짜 : 2017년 8월 10일
제작 목표 : 스택을 구현하고 활용한다.
"""

""" 런타임 에러 """

stk = []

# 입력
tc = int(input())

for i in range(tc):
	# 입력
	s = input()

	# 명령 실행
	if s == "pop":
		try:
			print(stk.pop())
		except IndexError:
			print(-1)
	elif s == "size":
		print(len(stk))
	elif s == "empty":
		if len(stk) == 0:
			print(1)
		else:
			print(0)
	elif s == "top":
		print(stk[len(stk) - 1])
	else:
		num = int(s.split(' ')[1])
		stk.append(num)