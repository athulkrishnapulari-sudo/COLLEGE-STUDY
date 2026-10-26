n=int(input("Enter the size of array : "))
print("Enter the Array : ")
a=[]
for i in range(n):
    a.append(int(input()))
for i in range(n):
    if a[i]%2==0:
        a[i]=a[i]/2
    else:
        a[i]=a[i]*2

print("New Array : ",a)