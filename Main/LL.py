class Node : 
    def __init__(self,value)  : 
        self.data = value 
        self.next = None 
class LinkedList :
    def __init__(self) :
        self.head = None # EMPTY LL
        self.n = 0
    def __len__(self) :
        return self.n
    def insertathead(self, value) :
        if self.head==None :
            self.head = Node(value)
            self.n+=1
        else :
            newnode = Node(value)
            newnode.next = self.head
            self.head = newnode
            self.n+=1 

    def append(self, value) :
        if self.head==None :
            self.head = Node(value)
            self.n+=1
        else :
            temp = self.head
            while temp.next!=None :
                temp = temp.next
            temp.next = Node(value)
            self.n+=1

    def insert_after(self,after,value) :
        newnode = Node(value) 
        current = self.head 
        while current!=None :
            if current.data == after: 
                break 
            current = current.next 
        if current!=None :
            newnode.next = current.next 
            current.next = newnode 
            self.n+=1
            print(self.traverse())
        else : 
            print('Node not found')



    def insertpos(self,index,item): 
        count = 0 
        temp = self.head 
        while count!= index : 
            temp = temp.next 
            count+=1
        newnode = Node(item)
        newnode.next = temp.next
        temp.next = newnode
        self.n+=1
    def traverse(self) :
        temp = self.head
        while temp!=None :
            print(temp.data, end = ' -> ')
            temp = temp.next
        print('None')
    def clear(self) :
        self.head = None
        self.n = 0
    def deletehead(self) :
        if self.head==None :
            return IndexError('Index out of range')
        self.head = self.head.next
        self.n-=1
    def pop(self) :
        if self.head==None :
            return IndexError('Index out of range')
        if self.head.next==None :
            ans = self.head.data
            self.head = None
            self.n=0
            return ans
        temp = self.head
        while temp.next.next!=None :
            temp = temp.next
        ans = temp.next.data
        temp.next = None
        self.n-=1
        return ans
       
    def deletepos(self, index) :
        if index<0 or index>=self.n :
            return IndexError('Index out of range')
        temp = self.head
        for i in range(index-1) :
            temp = temp.next
        temp.next = temp.next.next
        self.n-=1
    def remove(self, item) :
        # We're currently using the logic 
        # that we have to stop just before 
        # the item value 
        # but it won't be able to handle 
        # if the head itself is the item , 
        # hence this edge case isto be separately handled
        if self.head == None : 
            return IndexError('Index out of range')
        if self.head.data == item :
            self.head = self.head.next
            self.n-=1
            return
        current = self.head
        while current.next!= None : 
            if current.next.data == item : 
                break 
            current = current.next
        if current.next == None : 
            return "not found"
        else : 
            current.next = current.next.next
            self.n-=1
        
       
    def search(self,item) :
        count =0
        temp = self.head
        while temp!=None :
            if temp.data==item :
                return count
            count+=1
            temp = temp.next
        return False
    def __getitem__(self,index) :
        if index<0 or index>=self.n or self.head==None :
            return IndexError('Index out of range')
        temp = self.head
        for i in range(index) :
            temp = temp.next
        return temp.data

# testing 

llist = LinkedList()
llist.append(20)
llist.append(4)
llist.append(15)
llist.append(35)
llist.traverse()

llist.insertpos(2, 10)

llist.traverse()

print(llist.search(15))
print(llist.__getitem__(2))
llist.deletepos(2)
llist.traverse()
llist.remove(15)
llist.traverse()
llist.deletehead()

llist.traverse()
llist.pop()
llist.traverse()
llist.clear()

llist.traverse()

print(len(llist))  # should print 0 now as the list is empty.

print(llist.search(20)) # should print False as the list is empty.

print(llist.__getitem__(2)) # should print None as the list is empty.

llist.append(20)
  # should print 0 now as the list is empty.

print(llist.insert_after(20,30)) # should print 0 now as the list