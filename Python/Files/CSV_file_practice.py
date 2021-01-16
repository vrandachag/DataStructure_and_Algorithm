import csv
import os
'''
f =open("text1.txt", "w")
wt= csv.writer(f, delimiter='-')
wt.writerow(["sno", "name", "marks"])
wt.writerow([1,"Pratham",90])
wt.writerow([2,"Vranda",90])
f.close()

with open("r.csv", "r") as f:
   r= csv.reader(f, delimiter='-')
   for row in r :
        print(row)
'''
def Insert():
	f =open("text1.csv", "w")
	wt= csv.writer(f, delimiter='-')
	num = input("Enter number of entries:")
	for i in range(0,int(num)):
		employee = []
		name = input("Enter name:")
		employee.append(name)
		designation = input("Enter designation:")
		employee.append(designation)	
		salary = input("Enter salary:")
		employee.append(salary)
		wt.writerow(employee)
	f.close()

def Delete_entry():
	flag = 0
	f1 = open("text1_edit.csv", "w")
	wt= csv.writer(f1, delimiter='-')
	entry = input("Enter name of entry to be deleted:")
	with open("text1.csv", "r") as f:
		employee = csv.reader(f, delimiter='-')
		for emp in employee:
			if(emp[0] != entry):
				wt.writerow(emp)
		else:
			flag = -1
			print("Entry deleted")
	
	if flag != -1:
		print("Entry not found")
	f.close()
	f1.close()
	os.remove("text1.csv")
	os.rename("text1_edit.csv", "text1.csv")

def Search(name):
	f=open("text1.csv","r")
	employee = csv.reader(f, delimiter='-')
	for emp in employee:
#		employee = []
#		employee = csv.reader(f, delimiter='-')
		if emp[0] == name:
			print(emp)
			return emp
	else:
		print('entry not found')
		return -1
	f.close()

def Avg_calc():
	f= open("text1.csv","r")
	sum = 0
	count = 0
	employee = csv.reader(f, delimiter='-')
	for emp in employee:
		if emp[1].upper() == 'MANAGER':
			sum = sum + int(emp[2])
			count = count + 1
	if count > 0:
		print("Average of salaries of managers is:",sum/count)
	else:
		print("No entry with Manager as designation found")
	f.close()

def Modify():
	value = ["name","designation","salary"]
	f=open("text1.csv","r+")
	f1 = open("text1_edit.csv","w")
	wt = csv.writer(f1, delimiter='-')
	name = input("Enter name of employee:")
	
	employee = csv.reader(f, delimiter='-')
	for emp in employee:
		if emp[0] != name:
			wt.writerow(emp)
		else:
			detail = input("Enter detail to be modified:")
			idx = value.index(detail.lower())
			emp[idx] = input("Enter new value:")
			wt.writerow(emp)
	
	f.close()
	f1.close()
	os.remove("text1.csv")
	os.rename("text1_edit.csv", "text1.csv")


def Display():
	with open("text1.csv", "r") as f:
		r= csv.reader(f, delimiter='-')
		for row in r :
			print(row)

while 1:
	print("\n\n1.Display\n2.Insert\n3.Delete entry \n4.Search an entry \n5.Average calculation of salaries of Manager \n6.Modify an entry")
	choice = int(input("Enter choice:"))
	if choice == 1:
		Display()
	elif choice == 2:
		Insert()
	elif choice == 3:
		Delete_entry()
	elif choice == 4:
		Search("Hansa")
	elif choice == 5:
		Avg_calc()
	else:
		Modify()
	val = input("Want to enter more?(Y or N):")
	if val.upper() == 'N':
		break
