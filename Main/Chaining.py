# CHAINING # ARRAY OF LL
class Node : 
    def __init__(self,key,value)  : 
        self.key = key
        self.value = value 
        self.next = None 
class LinkedList :
    def __init__(self) :
        self.head = None
        self.n = 0
         # EMPTY LL

    def append(self,key, value) :
        if self.head==None :
            self.head = Node(key,value)
            self.n=1
        else :
            temp = self.head
            while temp.next!=None :
                temp = temp.next
            temp.next = Node(key,value)
            self.n+=1
    def traverse(self) :
        temp = self.head
        while temp!=None :
            print(temp.key, ': ',temp.value)
            temp = temp.next
    
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
       
    def remove(self, key) :
        # We're currently using the logic 
        # that we have to stop just before 
        # the item value 
        # but it won't be able to handle 
        # if the head itself is the item , 
        # hence this edge case isto be separately handled
        if self.head == None : 
            return IndexError('Index out of range')
        if self.head.key == key :
            self.head = self.head.next
            self.n-=1
            return
        current = self.head
        while current.next!= None : 
            if current.next.key == key : 
                break 
            current = current.next
        if current.next == None : 
            return "not found"
        else : 
            current.next = current.next.next
            self.n-=1
        
       
    def search(self,key) :
        count =0
        temp = self.head
        while temp!=None :
            if temp.key==key :
                return count
            count+=1
            temp = temp.next
        return False
    def getitem(self,index) :
        if index<0 or index>=self.n or self.head==None :
            return IndexError('Index out of range')
        temp = self.head
        for i in range(index) :
            temp = temp.next
        return temp.key
    
class Dictionary :
    def __init__(self,capacity) :
        self.capacity = capacity
        self.size = 0
        self.buckets = self.make_array(self.capacity) 

    def make_array(self,capacity) :
        return [LinkedList() for _ in range(capacity)]  
    def hashfunction(self,key) :
        return abs(hash(key))%self.capacity
    def get_node_index(self,hash_value,key) :
        node_index = self.buckets[hash_value].search(key)
        return node_index
    def put(self,key,value) :
        hash_value = self.hashfunction(key)
        node_index = self.get_node_index(hash_value,key)
        if node_index == False :
            self.buckets[hash_value].append(key,value)
            self.size+=1
        else :
            self.buckets[hash_value].getitem(node_index).value = value


#  Testing 
d = Dictionary(9)
d.put('Harry',76)
d.put('Ron',56)
d.put('Hermione',100)
d.put('Dumbledore',60)
d.put('Voldemort',45)
d.put('Tom',54)
d.put('Jerry',23)
print()
print(d.buckets[0].traverse())
print()   
print(d.buckets[1].traverse())
print()
print(d.buckets[2].traverse())
print()
print(d.buckets[3].traverse())
print()
print(d.buckets[4].traverse())
print()
print(d.buckets[5].traverse())
print()

print(d.buckets[6].traverse())
print()

print(d.size)

