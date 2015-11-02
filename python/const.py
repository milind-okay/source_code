class classname:
 def __init__(self):
  print "it's constructor"
 def __str__(self):
  return '__str__(self) call by print(obj) direct'
 
obj = classname()
print(obj)