n=int(input("Enter the size of array : "))
print("Enter the Array : ")
a=[]
for i in range(n):
    a.append(input())
vowels = "aeiouAEIOU"
for i in range(n):
    v=[]
    r=[]
    for j in a[i]:
        if j in vowels:
            v.append(j)
        else:
            r.append(j)
    print(f"Vowels of word - {a[i]} : {v}")
    print(f"Remaining Chars of word - {a[i]} : {r}")