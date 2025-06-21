class Node : 
    def __init__(self, data) : 
        self.data = data
        self.next = None
class Stack : 
    def __init__(self) : 
        self.top = None 
    def isempty(self) : 
        return self.top == None
    def push(self, data) :
        newnode = Node(data)
        newnode.next = self.top
        self.top = newnode
    def pop(self) :
        if self.isempty():
            print("Stack is empty")
            return
        popped = self.top
        self.top = self.top.next
        popped.next = None
        return popped.data
    def peek(self) :
        if self.isempty():
            print("Stack is empty")
            return
        return self.top.data
    def size(data) : 
        temp = data.top
        count = 0
        while temp != None :
            count += 1
            temp = temp.next
        return count 
    def display(self) :
        temp = self.top
        while temp != None :
            print(temp.data, end = ' ')
            temp = temp.next
        print() 
stack = Stack()
print(stack.isempty())
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)

print(stack.peek())
print(stack.size())
stack.display()
print(stack.pop())

class Stack : 
    def __init__(self,size) :
        self.size = size
        self.top =-1
        self.stack = [None]*size
        
    def push(self,value) :
        if self.top==self.size-1 :
            print("Stack is full")
        else :
            self.top+=1
            self.stack[self.top] = value
    def pop(self) : 
        if self.top==-1 :
            print("Stack is empty")
        else :
            self.top-=1
            return self.stack[self.top+1] 
    def isEmpty(self) :
        return self.top==-1
    def isFull(self) :
        return self.top==self.size-1
    def peek(self) :
        return self.stack[self.top]
    def display(self) :
        for i in range(self.top,-1,-1) :
            print(self.stack[i],end=' ')
        print()
stack = Stack(5)
print(stack.isEmpty())

stack.push(1)

stack.push(2)

stack.push(3)

stack.push(4)   

stack.push(5)
stack.display()
print(stack.pop())

