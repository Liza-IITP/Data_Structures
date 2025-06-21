def duplicatezeroes(arr) :
    i = 0 
    while i<=len(arr)-1: 
        if arr[i]==0 :
            arr.pop()
            arr.insert(i+1,0)
            i+=2
        else : 
            i+=1
            
    return arr

# Test Cases
print(duplicatezeroes([1,0,2,3,0,4,5,0])) # [1, 0, 0, 2, 3, 0, 0, 4]