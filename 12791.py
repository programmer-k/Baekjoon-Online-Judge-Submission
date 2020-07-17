"""
파일 이름 : 12791.py
제작자 : 정지운
제작 날짜 : 2017년 6월 24일
프로그램 용도 : David Bowie의 앨범을 출력한다.
"""

# 앨범 데이터 저장
album = (
(1967, "DavidBowie"),
(1969, "SpaceOddity"),
(1970, "TheManWhoSoldTheWorld"),
(1971, "HunkyDory"),
(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"),
(1973, "AladdinSane"),
(1973, "PinUps"),
(1974, "DiamondDogs"),
(1975, "YoungAmericans"),
(1976, "StationToStation"),
(1977, "Low"),
(1977, "Heroes"),
(1979, "Lodger"),
(1980, "ScaryMonstersAndSuperCreeps"),
(1983, "LetsDance"),
(1984, "Tonight"),
(1987, "NeverLetMeDown"),
(1993, "BlackTieWhiteNoise"),
(1995, "1.Outside"),
(1997, "Earthling"),
(1999, "Hours"),
(2002, "Heathen"),
(2003, "Reality"),
(2013, "TheNextDay"),
(2016, "BlackStar"))

# 입력
tc = int(input())

# tc의 크기만큼 반복
for i in range(tc):
	# 입력
	strList = input().split(' ')
	startYear = int(strList[0])
	endYear = int(strList[1])

	# 조건에 맞는 앨범 갯수를 구하고 데이터를 저장한다.
	outputList = []
	outputNum = 0
	for j in range(len(album)):
		if album[j][0] >= startYear and album[j][0] <= endYear:
			outputList.append(album[j])
			outputNum += 1
	
	# 출력
	print(outputNum)
	for j in range(len(outputList)):
		print(outputList[j][0], outputList[j][1])