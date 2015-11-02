num = 0
den = 0
while den != 1:
 print("enter num")
 num = float(raw_input())
 print("enter den")
 den = float(raw_input())
 if den == 0:
  continue
 print(num/den)
 