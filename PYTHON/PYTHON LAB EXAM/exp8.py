n=int(input("No of employees : "))
emp=dict()
for i in range(n):
    emp[int(input("Enter ID : "))] = [input("Enter your name : "),int(input("Enter your salary : "))]
print("sorted by keys : ",dict(sorted(emp.keys())))
print("sorted by values : ",dict(sorted(emp.values())))
empid=int(input("Enter the emp id to search"))

if empid in emp.keys():
    print("Employee details : ",emp[empid])
else:
    print("Not found")