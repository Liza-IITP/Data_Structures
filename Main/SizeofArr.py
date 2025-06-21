import sys 
L=[]
print(sys.getsizeof(L))
L.append(3)
print(sys.getsizeof(L))
L.append("Hello")
print(sys.getsizeof(L))
L.append("World")
print(sys.getsizeof(L)) 
L.append(72) 
print(sys.getsizeof(L)) 
L.append(2)
print(sys.getsizeof(L))
arr=[]
for i in range(40):
    arr.append(i)
    print(f"Length: {len(arr)} Size: {sys.getsizeof(arr)}") 
print(arr)