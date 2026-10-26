import re

pattern = r"^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%&*])[A-Za-z\d!@#$%&*]{8,}$"

input=input("Enter Password : ")

if re.match(pattern,input):
    print("valid")
else:
    print("Invalid")