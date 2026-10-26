import re

pattern = r"^[6-9]\d{9}$"

input = input("Enter a phone number : ")

if re.match(pattern,input):
    print("valid")
else:
    print("invalid")