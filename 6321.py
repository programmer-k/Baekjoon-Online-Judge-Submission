"""
파일 이름 : 6321.py
제작자 : 정지운
제작 날짜 : 2017년 6월 18일
프로그램 용도 : 여러 개의 문자열을 입력받아서, 각 알파벳을 다음 알파벳으로 바꿔서 출력한다.
"""

# 입력
n = int(input())

inputLst = []
for i in range(n):
	inputLst.append(input())

# 알파벳 변환
i = 1
for s in inputLst:
	output = ''
	for char in s:
		# 예외 사항
		if char == 'Z':
			output += 'A'
			continue
		output += chr(ord(char) + 1)

	# 결과 출력
	print("String #" + str(i))
	print(output)
	print()
	i += 1