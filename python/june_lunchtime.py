t = int(input())
while t>0:
 s1 = raw_input()
 s2 = raw_input()
 min = 0
 max = 0
 for i in range(0,len(s1)):
  if s1[i] != '?' and s2[i] != '?' and s1[i] != s2[i] :
    min+=1
  if s1[i] =='?' or s2[i] == '?' or s1[i] != s2[i] :
    max+=1
 print(str(min) + ' ' + str(max))
 t-=1
 
 
   