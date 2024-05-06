n = 185977  
k = 145541  

frm = n - k + 1
to = n
print("max:", ((frm + to) * (to - frm + 1)) / 2)

frm = 1
to = k
print("min:", ((frm + to) * (to - frm + 1)) / 2)