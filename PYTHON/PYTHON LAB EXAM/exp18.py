x=int(input("Num 1 : "))
y=int(input("Num 2 : "))
z=int(input("Num 3 : "))

largest = lambda x,y,z : x if x>=y and x>=z else y if y>=x and y>=z else z

print(largest(x,y,z))