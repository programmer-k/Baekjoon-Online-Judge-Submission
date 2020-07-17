"""
파일 이름 : 2857.py
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
"""

lst = []
for i in range(5):
	# 입력
	s = input()

	# FBI 요원인지 검사
	if s.find('FBI') != -1:
		lst.append(i + 1)

# 출력
for i in range(len(lst)):
	# 마지막 요소는 띄어쓰기 없이
	# if i == len(lst) - 1:
	#	print(lst[i])
	#	continue

	print(lst[i], end = ' ')

# FBI 요원이 한 명도 없을 때
if len(lst) == 0:
	print("HE GOT AWAY!")