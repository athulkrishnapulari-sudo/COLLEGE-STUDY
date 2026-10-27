class Person:
    def __init__(self,name,age,weight,height):
        self.name=name
        self.age =age
        self.weight = weight
        self.height = height

    def bmi_result(self):
        bmi = self.weight/((self.height/3.281)**2)
        if bmi<18.5:
            return "underweight"
        elif bmi>24.9:
            return "Overweight"
        elif bmi>29.9:
            return "Obese"
        else:
            return "Normal"

per = Person("Athul",18,74,5.41339)

print(per.bmi_result())