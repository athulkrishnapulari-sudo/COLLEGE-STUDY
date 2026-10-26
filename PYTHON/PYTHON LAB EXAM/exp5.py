a=(3,2,1,4,5)
print("Max : ",max(a))
print("Min : ",min(a))
print("Sum : ",sum(a))
print("Avg : ",sum(a)/len(a))
print("sorted : ",sorted(a))
print("reversed : ",tuple(reversed(a)))
print("without dup : ",tuple(set(a)))
b=(2,3,4,5,6)
c=a+b
print("merged : ",tuple(set(c)))
print(a[1:3])
a=b,c
print(b)
print(c)
a,b=b,a
tup=()
for i in range(1,11):
    tup+=(i**2,)
print(tup)
