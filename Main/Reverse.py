def reverse_array_using_stack(arr) :
    temp = arr
    stack=[]
    while len(temp)!=0 : 
        stack.append(temp.pop())
    return stack