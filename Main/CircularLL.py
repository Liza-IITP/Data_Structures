class CircularLLNode : 
    def __init__(self, data):
        self.data = data
        self.next = None
class CircularLL : 
    def __init__(self) : 
        self.head = None 
    def insert(self, data) :
        newnode = CircularLLNode(data)
        if not self.head : 
            self.head = newnode
            newnode.next = self.head
        else :
            temp = self.head 
            while temp.next!= self.head : 
                temp =temp.next 
            temp.next = newnode
            newnode.next = self.head
    def display(self) :
        temp = self.head 
        while temp.next!= self.head : 
            print(temp.data, end = " ")
            temp = temp.next
        print(temp.data)
        print(temp.data, end = " ")
        temp = temp.next
        while temp!= self.head : 
            print(temp.data, end = " ")
            temp = temp.next
        print()
    
        