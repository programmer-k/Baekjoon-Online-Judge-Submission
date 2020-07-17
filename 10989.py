"""
파일 이름 : 10989.py
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
프로그램 용도 : 숫자를 정렬해서 출력한다.
"""

""" 시간 초과로 인한 문제 풀이 실패 """

import sys

# 입력
tc = int(input())

lst = []

for i in range(tc):
	lst.append(int(sys.stdin.readline()))		# input 함수보다 readline함수가 더 빠르다고 함.

# 정렬 후 출력
lst.sort()

for i in range(tc):
	print(lst[i])