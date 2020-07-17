"""
파일 이름 : 1620.py
제작자 : 정지운
제작 날짜 : 2017년 7월 23일
제작 목표 : 딕셔너리를 사용한다.
"""

# 입력
tempList = input().split(' ')
pokNum = int(tempList[0])
probNum = int(tempList[1])

dic = {}
# 포켓몬의 이름을 딕셔너리에 저장한다.
for i in range(1, pokNum + 1):
	s = input()
	dic[str(i)] = s
	dic[s] = str(i)


# 문제 입력 및 계산
for i in range(probNum):
	s = input()
	print(dic[s])