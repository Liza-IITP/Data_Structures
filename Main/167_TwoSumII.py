def f(arr, sum) : 
    if len(arr) == 0 : return False
    left = 0 
    right = len(arr) - 1
    if left == right : 
        return False 
    while left < right :
        if arr[left] + arr[right] == sum : 
            return f"indices are : {left} , {right} WHICH ADD UPTO {sum}"
        elif arr[left] + arr[right] < sum :
            left+=1
        elif arr[left] + arr[right] > sum :
            right-=1 
    return False

