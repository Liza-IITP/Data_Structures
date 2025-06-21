class DoubleLL_Node : 
    def __init__(self,data): 
        self.data = data 
        self.next = None 
        self.prev = None 
class Double_LL : 
    def __init__(self) : 
        self.head = None 
    def insert_at_beginning(self,data) :
        newnode  = DoubleLL_Node(data) 
        if self.head == None : 
            self.head = newnode
            return self.head 
        self.head.prev = newnode
        self.head = newnode
        return self.head
    def insert_at_end(self,data) :
        newnode  = DoubleLL_Node(data) 
        if self.head == None : 
            self.head = newnode
            return self.head 
        last = self.head
        while(last.next):
            last = last.next
        last.next = newnode
        newnode.prev = last
        return self.head 
    def listtoDoubleLL(self,arr) : 
        for i in arr : 
            self.insert_at_end(i)
        return self.head
    def display(self) :
        temp = self.head
        while(temp) :
            print(temp.data,end = " ")
            temp = temp.next
        print()
    def display_reverse(self) :
        temp = self.head
        while(temp.next) :
            temp = temp.next
        while(temp) :
            print(temp.data,end = " ")
            temp = temp.prev
        print()

# test the code

dllist = Double_LL()
arr = [1, 2, 3, 4, 5]
dllist.listtoDoubleLL(arr)
dllist.display()
dllist.display_reverse()

