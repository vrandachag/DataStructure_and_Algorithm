class student:
  def __init__(self,n1 ="xyz", a=12):
    self.n=n1
    self.__age=a
  
  def indata(self):
    self.n= input("Enter name : ")
  def outdata(self):
    print("Name =", self.n, self.__age)

s=student(a=17, n1="Pratham")
s.outdata()
s1=student("vranda", "17")
s1.outdata()
s1.__age= 18
s1.outdata()
