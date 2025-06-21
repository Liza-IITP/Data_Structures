# imagine you're walking on the street and you have to search for next greatest height of apartments
# Say , heights are like these [4 , 5, 1, 2 ,3 ,6,7 ]
# For crossing the 0th apartment , you can't do anything , you move to next 
# since fortunately the 1st apartment is greater than you observed before you assigned it as result[0] 
# Now noting height of 2nd apartment which is smaller than 1st
#  you move to 3rd one which is more than second one so result[2]=3rd
# 4th one is more than 3rd but still not more than 1st , so result[3]=4th
# 5th one is more than 4th , so result[4]=5th , it's also more than 1st , result[1] = 5th
# 6th one more than 5th ,result[5]= 6th , no next element so -1 = result[6]
# ONCE WE ASSIGN THE Ith ELEMENT OF RESULT WE ALSO NEED TO REMOVE THE ELEMENT CORRESPONDINGLY IN THE HEIGHT LIST
def nextgreater(arr) : 
    n = len(arr) 
    stack=[]
    result=[-1]*n
    for i in range(n) :
        while len(stack)!=0 and arr[stack[-1]] <arr[i] : # if the current element is greater than the element at the top of stack
            index = stack.pop() 
            result[index] = arr[i] 
        stack.append(i) 
    return result 
print(nextgreater([4,5,1,2,3,6,7])) # [5,6,2,3,6,7,-1]
print(nextgreater([3,2,1])) # [-1,-1,-1]
print(nextgreater([1,2,3])) # [2,3,-1]
