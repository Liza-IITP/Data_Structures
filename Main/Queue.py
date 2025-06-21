# For queues head is front from where exit happens 
# and tail is rear from where entry happens
# Insertion is enqueue 
# Deletion is dequeue
# Queue follows FIFO (First In First Out) principle
# To maintain O(1) for insertion and deletion 
# we use two pointers approach of rear and front

class Node : 
    def __init__(self, data) :
        self.data = data
        self.next = None
class Queue : 
    def __init__(self) :
        self.front = self.rear = None
    def traverse(self) :
        if self.front == None : 
            print("Queue is empty")
            return 
        temp = self.front 
        while temp!= None : 
            print(temp.data,end=",")
            temp = temp.next
    def enqueue(self,value) :
        newnode = Node(value) 
        if self.rear== None : 
            self.front = newnode 
            self.rear = newnode 
        else :
            self.rear.next = newnode 
            self.rear = newnode

    def dequeue(self) :
        if self.front == None : 
            print("Queue is empty")
            return
        temp = self.front
        if(self.front == self.rear):
            self.front = self.rear = None
        else:
            self.front = self.front.next
        print("Dequeued item is", temp.data)
        del temp
arr= Queue()
arr.enqueue(10)
arr.enqueue(20)
arr.enqueue(30)
arr.enqueue(40)
arr.enqueue(50)
arr.enqueue(60)
arr.traverse()
print(arr.dequeue())

# Queue using 2 stacks 
# say if we have 1 2, 3, 4,5,6,7
#  stack1 = [1,2,3,4,5,6,7]
# stack2 = [7,6,5,4,3,2,1]
# to enqueue we use stack1 
# to dequeue we use stack 2

# Implementation 
class Queue : 
    def __init__(self) :
        self.stack1=[]
        self.stack2=[]
    def enqueue(self,value) :
        self.stack1.append(value) 
    def dequeue(self) :
        if len(self.stack1) ==0 :
            return 
        while len(self.stack1)!=0 :
            self.stack2.append(self.stack1.pop())
        self.stack2.pop()
arr =Queue()
arr.enqueue(10)
arr.enqueue(20)
arr.enqueue(30)
arr.enqueue(40)
arr.enqueue(50)
arr.enqueue(60)
arr.dequeue()