size=int(input("Enter the size of array"))
print("Enter the list elements")
a=[]
for i in range(0,size):
    a.append(int(input()))
target = int(input("Enter the target Number : "))
flag=0
for i in range(size):
    for j in range(size): 
        if(a[i]+a[j]==target):
            print("Pair  : ",a[i],a[j])
            flag=1
if flag==0:
    print("No Pair Found.")
