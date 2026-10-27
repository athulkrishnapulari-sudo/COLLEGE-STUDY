class Instructor:
    followers = 0 #CLASS OBJECT VARIABLE
    def __init__(self,name,address):
        self.name = name
        self.address = address
    def display(self):
        print("Name : ",self.name)
        print("Address : ",self.address)
        print("Followers : ",Instructor.followers)
    def update(self):
        Instructor.followers+=1


inst =  Instructor("Athul","Kerala")


print(inst.name)
inst.followers=10
print(inst.followers)
inst.display()
inst.update()
inst.display()
