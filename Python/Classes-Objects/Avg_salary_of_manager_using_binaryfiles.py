import pickle

class Employee:
	def __init__(self,name = '',designation = '',salary = 0):
		self.name = name
		self.designation = designation
		self.salary = salary
	
	def outdata(self):
		print(self.name,self.designation,self.salary)

	

def indata():
		f=open("data.txt","ab")
		name = input("Enter name:")
		designation = input("Enter designation:")
		salary = input("Enter salary:")
		e = Employee(name,designation,salary)
		pickle.dump(e,f)
		f.close()

def avg():
	global sum
	global count
	f=open("data.txt","rb")
	e = Employee()
	try:
		while True:
			e=pickle.load(f)
			if e.designation.upper() == 'MANAGER':
				e.outdata()
				sum = sum + int(e.salary)
				count = count + 1
	except EOFError:
		if count !=0 :
			print("Average of salaries of managers is:",sum/count)
		else:
			print("Entry not found")
		f.close()

sum = 0
count = 0
num = input("Enter number of entries:")
emp = Employee()

for i in range(0,int(num)):
	indata()
avg()
