a={
    101:{'Name':'Anu','Marks':90},
    102:{'Name':'Rahul','Marks':80},
    103:{'Name':'Arun','Marks':70}
}
print(a)
roll=int(input("Enter roll"))
if roll in a:
    print("Details : ",a[roll])
else:
    print("Not Found")