# Write for max value in LL and replace it with given
class Node : 
    def __init__(self, data) :
        self.data = data
        self.next = None
def printLL(head) :
    temp = head 
    while temp!= None : 
        print(temp.data,end=' ')
        temp = temp.next
def find_max(head,replaceval) : 
    max =head 
    temp = head
    while temp!= None : 
        if temp.data>max.data : 
            max = temp
        temp = temp.next
    max.data = replaceval
# sum at odd place
def sumodd(head) : 
    temp = head  
    count = 0
    sum =0 
    while temp!= None : 
        if count%2!=0 :
            sum+=temp.data
        count+=1
        temp = temp.next
    return sum
# To get the output of given program 
# i/p = 1,2,3,4,5

def func(head) : 
    if(head == None) : 
        return 
    if head.next.next!= None : 
        print(head.data," ",end='')
        func(head.next) 
    print(head.data," ",end='')
first = Node(1)
second  = Node(2) 
third = Node(3)
fourth = Node(4)
fifth = Node(5)
first.next = second
second.next = third
third.next = fourth
fourth.next = fifth

func(first)

# Reverse a Linked List 
def reverse(head) : 
   prev = None 
   current = head 
   while current!= None : 
       temp = current.next
       current.next = prev
       prev = current
       current = temp 
   head = prev
   printLL(head) 
reverse(first)

# to replace * or / by single space
# to replace */ or // or ** by space and capitalise next

def change_sent(head) : 
    temp = head 
    while temp!= None :
        if temp.data =="*" or temp.data =="/" : 
            temp.data =" "
            if temp.next.data == "*" or temp.next.data == "/":                                                             
                temp.next.next.data = temp.next.next.data.upper()
                temp.next = temp.next

        temp = temp.next
    return head

# test 
A= Node("*")
a = Node("T")
b = Node("h")
c= Node("e")
d= Node("*")
e =Node("s") 
f = Node("k")
g = Node("y")
B= Node("/")
h = Node("i")
i = Node("s")
C= Node("*")
D = Node("/")
j = Node("b")
k = Node("l")
l = Node("u") 
m = Node("e") 

A.next = a
a.next = b
b.next = c
c.next = d
d.next = e
e.next = f
f.next = g
g.next = B
B.next = h  
h.next = i
i.next = C
C.next = D
D.next = j
j.next = k
k.next = l
l.next = m
printLL(change_sent(A))






