import csv

f=open('students.csv','r')

dt = csv.reader(f)

data = list(dt)
data.pop(0)

f.close()

f = open('high_marks.csv','w',newline='\n')

dt = csv.writer(f)

dt.writerow(['id','Name','Mark'])

for i in data:
    if int((i[2]))>50:
        dt.writerow(i)

f.close()

# to print the contents of new file 

f=open('high_marks.csv','r')

dt = csv.reader(f)

data = list(dt)

print(data)

f.close()