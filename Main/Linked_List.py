# to take input for linked list : 
# we'll first define a function which returns
# a head to newly created linked list

class Node:
    def __init__(self,value) :
        self.value = value
        self.next = None 
def printLL(head) : 
    temp = head
    while temp!=None :
        print(temp.value, end=" ")
        print(" -> " if temp.next!=None else "", end="")
        temp = temp.next

    return 

def take_input() :
    value = int(input("Enter the value of node : ")) 
    head = None
    while value!=-1 :
        # creating a new node
        new_node = Node(value)
        # if head is None, then make this new node as head
        if head== None : 
            head = new_node
        else : 
            # traverse to the end of the linked list
            last_node = head
            while last_node.next!=None :
                last_node = last_node.next
            # change the next of last_node to new_node
            last_node.next = new_node  # this will make the new node as last node in linked list
        value = int(input("Enter the value of node : ")) 
        
    return head
x=take_input()
printLL(x)




