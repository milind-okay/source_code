n = int(input())
num = []
um = raw_input()
num = um.split(' ')
#print(num)
for i in range(0,n):
 #num = int(input())
 x = int(num[i])*4
 y = int(num[i])*7
 z = int(num[i])*28
 sum_x = 0
 sum_y = 0
 sum_z = 0
 while x%10 == 0 :
  x = x/10
  sum_x += 1
 while y%10 == 0 :
  y = y/10
  sum_y += 1
 while z%10 == 0 :
  z = z/10
  sum_z += 1
 if sum_x == 0 and sum_y == 0 and sum_z == 0 :
  print(int(num[i]))
 else:
  if sum_x >= sum_y:
   if sum_x >= sum_z:
    print(int(num[i])*4)
   else:
    print(int(num[i])*28)
  else:
   if sum_y >= sum_z:
    print(int(num[i])*7)
   else:
    print(int(num[i])*28)
 
 
 