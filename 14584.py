"""
파일 이름 : 14584.py
제작자 : 정지운
제작 날짜 : 2017년 5월 28일
"""
import sys

# 암호문을 입력 받는다.
password = input()

# 단어 개수와 각 단어를 입력받는다.
num = int(input())

# 단어는 리스트에 저장한다.
wordlst = []
for i in range(num):
	word = input()
	wordlst.append(word)

# 알파벳을 한 칸씩 평행이동하면서 암호문을 검사한다.
# 한 칸씩 평행이동하므로 총 26번을 반복한다.
temp_password = ''
for i in range(1, 27):

	# 문자 하나하나씩 평행이동을 시킨다.
	for ch in password:
		if ch != 'z':
			temp_password += chr(ord(ch) + 1)
		# 문자가 z인 경우에는 a로 이동시킨다.
		else:
			temp_password += 'a'
	
	# 단어가 포함되어 있는지 검사한다.
	for j in range(num):

		# 단어가 포함되어 있으면 그 암호문을 해석한 것이므로 그 암호문을 출력하고 프로그램을 종료한다.
		if wordlst[j] in temp_password:
			print(temp_password)
			sys.exit()
	
	# 단어가 포함되어 있지 못하면 여태까지 해 왔던 것들을 반복한다.
	# password를 변경시켜야지 변경된 자리에서 평행이동시킬 수 있다.
	password = temp_password
	temp_password = ''