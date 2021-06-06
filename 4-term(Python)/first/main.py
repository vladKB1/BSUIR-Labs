a = [10, -4, 37, 42, 11, 89, 605, 47, -39, -1001]

print("Array a:", a)

mx = a[0]
for i in range(10):
    if a[i] > mx:
        mx = a[i]

print("Maximum is:", mx)
