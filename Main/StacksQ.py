# String reversal using stack 
# First we'll push the string 
# into the stack and 
# then popping it gives the reverse of it
class Node : 
    def __init__(self,data):
        self.data = data 
        self.next = None
class Stack:
    def __init__(self):
        self.head = None
    def push(self,data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
    def pop(self):
        if self.head is None:
            return None
        else:
            temp = self.head.data
            self.head = self.head.next
            return temp
    def printStack(self):
        temp = self.head
        while temp is not None:
            print(temp.data,end=" -> ")
            temp = temp.next
    def reverse(string):
        stack = Stack()
        for char in string:
            stack.push(char)
        reversed_string = ""
        while not stack.isEmpty():
            reversed_string += stack.pop()
        return reversed_string 
    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False
    def size(self):
        temp = self.head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next
        return count
        
string = "HELLO"

print("Original String:", string)

reversed_string = Stack.reverse(string)
print("Reversed String:", reversed_string)

# it's not good approach as you have SC = O(n) 
# and TC = O(n) 
# we thus don't use stack for reversal 
# unless specified


# Below is an approach with a time complexity of O(n) and space complexity of O(1)
# This is done by using two pointers approach
# One pointer is at the start and the other at the end

def reverse_string(s):
    left = 0
    right = len(s) - 1

    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1


# Text Editor undo redo
def undo_redo_string(string,operation) : 
    stack_operation = Stack()
    stack_string = Stack()
    prev_data = None
    for i in string : 
        stack_string.push(i)
    for i in operation :
        stack_operation.push(i)
    while stack_operation.isEmpty() == False:
        op = stack_operation.pop()
        if op.lower() == 'u':
            prev_data = stack_string.pop()
        elif op.lower()== 'r':
            stack_string.push(prev_data)
    return stack_string.printStack()

string = "HELLO"
operation = "UUURR"
print(undo_redo_string(string,operation))
u = "Kolkata"
r = "uurrurur"

print(undo_redo_string(u,r))

# Celebrity problem 
A = [[0,0,1,1],[0,0,1,1],[1,0,1,1],[0,0,0,0]]
def find_celeb(matrix) : 
    s = Stack() 
    for i in range(len(matrix)) : 
        s.push(i) 
    s.printStack()
    print()
    while s.size()>=2 :
        a = s.pop()
        b = s.pop()
        if matrix[a][b] == 1 :
            s.push(b)
        else:
            s.push(a)
    celeb = s.pop()
    for i in range(len(matrix)) :
        if i != celeb and (matrix[celeb][i] == 1 or matrix[i][celeb] == 0) :
            return -1
    return celeb

print(find_celeb(A))

#BALANCED BRACKET PROBLEM 

def is_balanced(s):
    stack = Stack()
    mapping = {'(': ')', '[': ']', '{': '}'}
    for char in s : 
        if char in mapping.keys() :
            stack.push(char) 
        elif char in mapping.values() : 
            if stack.isEmpty() or char!=mapping[stack.pop()] : 
                return False
    return stack.isEmpty()

print(is_balanced("()[]{}")) # True
print(is_balanced("([)]")) # False
print(is_balanced("[{(a+b)*(c+d)}]")) # True