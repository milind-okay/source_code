t = int(input())
while t>0 :
 st = raw_input()
 s = []
 s = st.split(' ')
 flag = 0
 for i in range(0, 6):
  num = 0
  color = s[i]
  #print(color)
 
  if i%2 == 0:
   k = (i + 1)%6
   for l in range(0,4) :
    k = (k + 1)%6
    #print(s[k] + " == " + color)
    if s[k] == color:
     num += 1
    
  else:
  	k = (i-1)%6
  	for l in range(0,4):
	 if k == 0 :
	  k = 6
	 k = (k-1)%6
  	 if s[k] == color:
  	  num +=1
  #print(num)
  if num >= 2 :
   flag = 1
   # print(num)
   break
   
 if flag == 1:
  print("YES\n")
 else:
  print("NO\n")
  
 
 t-=1