import pickle

class Employee:
	def __init__(self):
		self.l = []

	def indata(self):
		f=open("data.txt","ab")
		name = input("Enter name:")
		self.l.append(name)
		designation = input("Enter designation:")
		self.l.append(designation)
		salary = input("Enter salary:")
		self.l.append(salary)
		pickle.dump(self.l,f)
	
	def avg(self):
		global sum
		global count
		f=open("data.txt","rb")
		try:
			while True:
				self.l=pickle.load(f)
				if self.l[1].upper() == 'MANAGER':
					sum = sum + int(self.l[2])
					count = count + 1
		except EOFError:
			print("Average of salaries of managers is:",sum/count)
			f.close()

sum = 0
count = 0
num = input("Enter number of entries:")
emp = Employee()

for i in range(0,int(num)):
	emp.indata()
emp.avg()
