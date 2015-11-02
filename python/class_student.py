class student:
 grade = []
 def __init__(self, name ,id):
   self.name = name
   self.id = id
   
 def add_grade(self,num):
   return self.grade.append(num)
 def showgrades(self):
   grades = ' '
   for grd in self.grade:
    grades += str(grd) + ' '
   return grades
   
 def ave(self):
  sum = 0
  for i in self.grade:
   sum += i
  return str(sum/len(self.grade))
 def __str__(self):
   return "name : " + self.name + "\n" + \
           "id : " + self.id + "\n" + \
		   "Grades : " + self.showgrades() + "\n" +\
		   "Ave : " + self.ave()
 
stu1 = student('Milind','1001')
stu1.add_grade(80)
stu1.add_grade(30)
stu1.add_grade(85)
print(stu1)