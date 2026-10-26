import csv 

# f = open("students.csv", "a", newline="")
# writer = csv.DictWriter(f,fieldnames=["id","Name","Mark"])
# writer.writeheader()

# row = {"id": 1, "Name": "Athul", "Mark": 95}

# writer.writerow(row)


f=open("students.csv","r")
reader = csv.DictReader(f)
for i in reader:
    print(i)