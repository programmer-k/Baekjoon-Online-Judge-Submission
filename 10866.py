"""
파일 이름 : 10866.py
제작자 : 정지운
제작 날짜 : 2018년 1월 10일
"""
from collections import deque

# 덱 생성
deq = deque()

# tc 입력 받기
tc = int(input())

# tc만큼 반복
for i in range(tc):
	# 명령문 입력
	s = input()
	
	# 명령문 처리
	if s == "size":
		print(len(deq))
	elif s == "empty":
		if len(deq) == 0:
			print(1)
		else:
			print(0)
	elif s == 'back':
		try:
			print(deq[len(deq) - 1])
		except IndexError:
			print(-1)
	elif s == 'front':
		try:
			print(deq[0])
		except IndexError:
			print(-1)
	elif s == 'pop_back':
		try:
			print(deq.pop())
		except IndexError:
			print(-1)
	elif s == 'pop_front':
		try:
			print(deq.popleft())
		except IndexError:
			print(-1)

	# 나머지 명령문들은 숫자 변환이 다 필요하므로 숫자 변환 먼저 하기
	try:
		num = int(s.split(' ')[1])
	except IndexError:
		continue

	# 명령문들도 미리 분리해놓기
	s = s.split(' ')[0]

	# 계속해서 명령문 처리
	if s =='push_back':
		deq.append(num)
	elif s == 'push_front':
		deq.appendleft(num)
	