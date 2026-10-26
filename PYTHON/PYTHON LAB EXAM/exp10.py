a=[
    "Athul 91-974778988","Anu 541-56473721","Alif 987-98675645"
]
import re

# pattern = r"\d{3}-\d{8}"

# name = r"[a-zA-z]+"

# for i in a:
#     if re.search(pattern,i):
#         print(re.findall(name,i)[0])


#or pattern can be "(\w+)\s(\d{3})-(\d{8})"

pattern = r"(\w+)\s(\d{3})-(\d{8})"

for i in a:
    match = re.search(pattern,i)
    if match:
        print(match.group(1))
