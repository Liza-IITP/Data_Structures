def Winner_Of_Circular_Game(n,k) : 
    arr =list(range(1,n+1)) 
    i =0
    start_pointer = arr[i]
    for i in range(0,len(arr)-1):
        start_nextpointer = arr[i+k]
        arr.pop((i+k-1)%len(arr)) 

# Test the function
n = 5
k = 3
print(Winner_Of_Circular_Game(n,k))  
# Output : 4
        

    