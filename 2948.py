"""
파일 이름 : 2948.py
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
"""

# 입력
tempList = input().split(' ')
day = int(tempList[0])
month = int(tempList[1])

# 계산
totalDay = 0
for num in range(1, month):
	if num in (1, 3, 5, 7, 8, 10, 12):
		totalDay += 31
	elif num == 2:
		totalDay += 28	# 윤년이 아니다
	else:
		totalDay += 30

totalDay += day

ans = totalDay % 7
# 출력
if ans == 1:
	print("Thursday")
elif ans == 2:
	print("Friday")
elif ans == 3:
	print("Saturday")
elif ans == 4:
	print("Sunday")
elif ans == 5:
	print("Monday")
elif ans == 6:
	print("Tuesday")
else:
	print("Wednesday")