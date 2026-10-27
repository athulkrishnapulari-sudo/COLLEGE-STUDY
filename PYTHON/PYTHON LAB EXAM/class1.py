class Human:
    def __init__(self,name):
        self.name=name
    def eat(self):
        print("I can Eat")
    def work(self):
        print("I can Work")


class Male:
    def __init__(self,age):
        self.age=age
    def work(self):  
        print("I cannot work")

class Boy(Human,Male):
    def __init__(self,age):
        Human.__init__(self,"Athul")
        Male.__init__(self,age)
        print("age : ",self.age)

person1 = Boy(10)

person1.eat()
person1.work()

Male.work(person1)

print(Boy.mro())
