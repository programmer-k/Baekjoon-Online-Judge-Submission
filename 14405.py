s = input()

# kpia가 입력으로 주어지면 먼저 pi가 지워져서 ka가 되고, ka도 지워져서 빈 문자열이 되므로 NO가 출력되야 하는데, YES가 출력된다.
'''
if s.replace("pi", "").replace("ka", "").replace("chu", ""):
    print("NO")
else:
    print("YES")
'''

temp = s.replace("pi", "")
pikachu = temp.replace("ka", "").replace("chu", "")
pichuka = temp.replace("chu", "").replace("ka", "")

temp = s.replace("ka", "")
kapichu = temp.replace("pi", "").replace("chu", "")
kachupi = temp.replace("chu", "").replace("pi", "")

temp = s.replace("chu", "")
chupika = temp.replace("pi", "").replace("ka", "")
chukapi = temp.replace("ka", "").replace("pi", "")

if pikachu or pichuka or kapichu or kachupi or chupika or chukapi:
    print('NO')
else:
    print('YES')