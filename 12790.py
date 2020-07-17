"""
파일 이름 : 12790.py
제작자 : 정지운
제작 날짜 : 2017년 6월 23일
프로그램 용도 : 캐릭터의 최종 전투력을 출력한다.
"""

# 입력
TC = int(input())

# TC의 수만큼 반복한다.
for i in range(TC):
	# 입력
	s = input()
	s = s.split(' ')

	# 대입
	HP = int(s[0])
	MP = int(s[1])
	ATK = int(s[2])
	DEF = int(s[3])

	# 나머지 4개의 데이터 대입
	HP += int(s[4])
	MP += int(s[5])
	ATK += int(s[6])
	DEF += int(s[7])

	# 특수 조건 검사
	if HP < 1:
		HP = 1
	if MP < 1:
		MP = 1
	if ATK < 0:
		ATK = 0
	
	# 최종 전투력 계산 및 출력
	combatPower = HP + 5 * MP + 2 * ATK + 2 * DEF
	print(combatPower)