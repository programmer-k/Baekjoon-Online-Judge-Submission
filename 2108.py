'''
파일 이름 : 2108.py
제작자 : 정지운
제작 날짜 : 2018년 6월 5일
'''

"""
lst = []
n = int(input())

for i in range(n):
    lst.append(int(input))



print(round(sum(lst) / len(lst)))
print(lst[len(lst) // 2])
print(max(lst) - min(lst))
"""



# statistics module을 python tutorial에서 보고 난 후 재도전

from statistics import mean, median, mode, StatisticsError
from operator import itemgetter
import sys

lst = []
modeDic = {i : 0 for i in range(-4000, 4001)}
n = int(sys.stdin.readline())

for i in range(n):
    num = int(input())
    lst.append(num)
    modeDic[num] += 1

print(round(mean(lst)))
print(median(lst))
# mode.items()가 key 값을 기준으로 오름차순 정렬되어 있다고 가정할 때, key에는 가장 작은 최빈값이 저장됨.
key = max(modeDic.items(), key=itemgetter(1))[0]

# 가장 작은 최빈 값 지우기
del modeDic[key]

# 가장 작은 최빈 값을 찾아서 출력하면 기존의 데이터에서 두 번째로 작은 최빈 값을 출력하는 것임.
print(max(modeDic.items(), key=itemgetter(1))[0])
print(max(lst) - min(lst))