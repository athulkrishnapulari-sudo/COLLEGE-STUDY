t=((1,2,3),(4,5,6))
print(t[0][1])
print(t[1][2])
a=(1,2,3,4)
largest=max(a)
second=a[0]
for i in a:
    if i>second and i<largest:
        second=i
print("second largest : ",second)
b=(1,2,3,4,5)
odd=()
even=()
for i in b:
    if(i%2==0):
        even+=(i,)
    else:
        odd+=(i,)
print("Even Tuple : ",even)
print("Odd Tuple : ",odd)

c=(1,1,1,2,3,4,5,5,5)
for i in set(c):
    count = c.count(i)
    print(f"{i} occured {count} times")

common=()

for x in a:
    if x in b and x not in common:
        common = common + (x,)
print("Common : ",common)

a=(1,2,3,3,4)
re=3
remove=()
for i in a:
    if i!=re:
        remove+=(i,)

print(remove)