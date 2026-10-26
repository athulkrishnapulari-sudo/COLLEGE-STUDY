#to convert a list to tuple and tuple to list

n=int(input("Enter the size of list : "))
print("Enter the list : ")
a=[]
for i in range(n):
    a.append(int(input()))
tup=()
for i in a:
    tup+=(i,)
print("The tuple converted from list : ",tup)


n=int(input("Enter the size of tuple : "))
print("Enter the tuple")
tuple=()
for i in range(n):
    tuple+=(int(input()),)
list=[]
for i in tuple:
    list.append(i)
print("The list converted from tuple : ",list)