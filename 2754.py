"""
파일 이름 : 2754.py
제작자 : 정지운
제작 날짜 : 2017년 7월 27일
프로그램 용도 : 성적의 평점을 출력한다.
"""

# 입력
score = input()

# 평점 출력
if score == 'A+':
	print(4.3)
elif score == 'A0':
	print(4.0)
elif score == 'A-':
	print(3.7)
elif score == 'B+':
	print(3.3)
elif score == 'B0':
	print(3.0)
elif score == 'B-':
	print(2.7)
elif score == 'C+':
	print(2.3)
elif score == 'C0':
	print(2.0)
elif score == 'C-':
	print(1.7)
elif score == 'D+':
	print(1.3)
elif score == 'D0':
	print(1.0)
elif score == 'D-':
	print(0.7)
else:
	print(0.0)