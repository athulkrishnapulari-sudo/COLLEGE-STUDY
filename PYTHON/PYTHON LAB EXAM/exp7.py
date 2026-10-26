roll=int(input("Enter the Roll Number : "))
name=input("Enter the name : ")
marks = int(input("Enter the marks : "))
student = dict()
student['Roll'] = roll
student['Name']=name
student['Marks']=marks

print("Dictionary : ",student)

student['Marks']=int(input("Enter the new marks"))
print("Updated Dictionary : ",student)

student['Age'] = int(input("Enter student Age : "))

print(student)

del student[input("Enter the Key to Delete : ")]

print(student)

key = input("Enter a key")

keys = student.keys()

if key in keys:
    print(key," : ",student[key])
else:
    print("key Not Found")

print(student.keys())
print(student.values())
print(student.items())