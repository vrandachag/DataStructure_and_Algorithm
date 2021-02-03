import pickle

class Employee:
    def __init__(self):
        f=open("data.txt","ab")
        self.l = []
    	name = input("Enter name:")
	    self.l.append(name)
	    designation = input("Enter designation:")
	    self.l.append(designation)
	    salary = input("Enter salary:")
	    self.l.append(salary)
	    pickle.dump(l,f)
    
    def avg(self):
        global sum
        global count
        f=open("data.txt","rb")
        try:
            while True:
                l=pickle.load(f)
                if l[1].upper == 'MANAGER':
                    sum = sum + int(l[2])
                    count = count + 1
        except EOFError:
        print("Average of salaries of managers is:",sum/count)
        f.close()
num = input("Enter number of entries:")
for i in range(0,int(num)):
	
f.close()

sum = 0
count = 0
