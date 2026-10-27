class Student:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def display(self):
        print("DETAILS")
        print("Name : ",self.name)
        print("Age : ",self.age)

class Sports:
    def __init__(self,sports):
        self.sports=sports
    def displaysports(self):
        print("Sports Mark : ",self.sports)

class Derived(Student,Sports):
    def __init__(self, name,age,sportsmark,mark1,mark2,mark3):
        Student.__init__(self,name,age)
        Sports.__init__(self,sportsmark)
        self.mark1 = mark1
        self.mark2 = mark2
        self.mark3 = mark3
        self.totalmark = self.sports+self.mark1+self.mark2+self.mark3
    def display(self):
        Student.display(self)
        Sports.displaysports(self)
        print("Total Mark : ",self.totalmark)

obj = Derived("Athul",18,90,67,87,98)
obj.display()