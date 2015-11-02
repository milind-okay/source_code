num = [4,7]
i = 0
j = 2
for k in range(0,9):
 for q in range(i,i+j):
  num.append(num[q]*10 + 4)
  num.append(num[q]*10 + 7)
 i = i + j
 j = j*2
 
print(len(num))