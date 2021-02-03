class Employee:
  def __init__(self):
    self.name = input("Enter name of Employee:")
    self.designation = input("Enter designation:")
    self.salary = int(input("Enter salary:"))
    
  def avg(self):
      global total
      global count
      if self.designation.upper() == "MANAGER":
          total=total+self.salary
          count=count+1
          
n = int(input("Enter number of entries:"))
l=[]
total=0
count=0
for i in range(0,n):
  e1 = Employee()
  l.append(e1)

for emp in l :
  emp.avg()

print("Average of salaries:" + str(total//count))
