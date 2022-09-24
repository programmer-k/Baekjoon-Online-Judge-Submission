s = input()
if len(s) == 2:
    print(int(s[0]) + int(s[1]))
elif len(s) == 3:
    if s.find('10') == 0:
        print(10 + int(s[2]))
    else:
        print(int(s[0]) + 10)
else:
    print(20)
