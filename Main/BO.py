class Hashmap :
    def __init__(self,capacity):
        self.size =0 
        self.capacity = capacity
        self.keys = [None]*capacity
        self.values = [None]*capacity
    def put(self,key,value):
        if self.size == self.capacity:
            return
        index = hash(key)%self.capacity
        while self.keys[index] != None:
            if self.keys[index] == key:
                self.values[index] = value
                return
            index = (index+1)%self.capacity
        self.keys[index] = key
        self.values[index] = value
        self.size +=1
    def get(self,key):
        index = hash(key)%self.capacity
        while self.keys[index]!= None:
            if self.keys[index] == key:
                return self.values[index]
            index = (index+1)%self.capacity
        return None
    def remove(self,key):
        index = hash(key)%self.capacity
        while self.keys[index]!= None:
            if self.keys[index] == key:
                self.keys[index] = None
                self.values[index] = None
                self.size -= 1
                return
            index = (index+1)%self.capacity
        return None
    def display(self):
        for i in range(self.capacity):
            if self.keys[i] != None:
                print(self.keys[i],self.values[i])
    def size(self):
        return self.size
    def isEmpty(self):
        return self.size == 0
    
    def __setitem__(self,key,value):
        self.put(key,value)
    def __getitem__(self,key):
        return self.get(key)

a = Hashmap(10)
a.put("apple",100)  
a.put("banana",200)
a.put("mango",300)
print(a.display())

a.put("apple",400)
print(a.display())

print(a["banana"])
a.remove("apple")
print(a.display())