tc = int(input())

for i in range(tc):
	s = input()
	num = int(s.split(' ')[0])
	s = s.split(' ')[1]

	for ch in s:
		print(ch * num, end = '')
	print()