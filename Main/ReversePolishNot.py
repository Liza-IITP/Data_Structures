def reversepolishnotation(arr) : 
    operations =["+","-","*","/" ] 
    stack =[] 
    for i in arr : 
        if i not in operations : 
            stack.append(int(i)) 
        else : 
            a = stack.pop()
            b = stack.pop() 
            if i == "+" : 
                stack.append(b + a) 
            elif i == "-" :
                stack.append(b - a)
            elif i == "*" :
                stack.append(b * a)
            else :
                stack.append(int(b/a))
    return stack[0] 
# Driver code
arr = ["4", "13", "5", "/", "+"] 

print("Result is : ", reversepolishnotation(arr))