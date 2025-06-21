class StacksusingList : 
    def __init__(self) : 
        self.stack =[] 
    # Note that in stack we have isempty,push ,pop,top/peek and size are basic operations for any stack 
    def push(self,data) :
        self.stack.append(data)
    # Note that for stack , it the last one to come first out like chips in th pringles can 
    def top(self) :
        return self.stack[-1]
    def size(self) :
        return len(self.stack) 
    def pop(self):
        return self.stack.pop() 
    def isempty(self) :
        return len(self.stack)==0 # you can't check here using self.stack.size()==0 because size is not attribute for list which is self.stack
    def printstack(self) :
        print(self.stack) 
# let's test these : 
stack = StacksusingList()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
stack.printstack()
print(stack.pop())
stack.printstack()
print(stack.top())
print(stack.size())
print(stack.isempty())
stack.pop()
stack.pop()
stack.pop()
print(stack.isempty())
stack.printstack()



# implementation using linked list : 
class Node : 
    def __init__(self,data) :
        self.val = data 
        self.next = None 
class StacksusingLL : 
    def __init__(self) :
        self.head = None 
        self.len = 0 
    
    def push(self,data) :
        self.len+=1 
        nn = Node(data) 
        if self.head==None :
            self.head = nn
        else :
            nn.next = self.head
            self.head =nn
    def top(self) : 
        if (self.head==None or self.size==0) :
            return None 
        return self.head.val 
    def size(self) :
        return self.len
    def pop(self) :
        if self.head==None or self.len==0 :
            return None 
        dataattop = self.head.val
        self.head = self.head.next
        self.len-=1
        return dataattop
    def isempty(self) :
        return self.len==0 
   
# let's test these :
stack = StacksusingLL() 
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4) 

print(stack.pop())


print(stack.top())
print(stack.size())
print(stack.isempty())
print(stack.pop())
print(stack.pop())
print(stack.pop())
print(stack.pop())

print(stack.isempty())


            
            

        

