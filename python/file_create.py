outfile = open('text_file.txt','w')
outfile.write('Hello its program created file \n')
outfile.write('nex line')
#lets write through the loop
#outfile = open('new.txt','w')
x=0
while x<=10:
 outfile.write(str(x))
 x = x + 1
outfile.close()
