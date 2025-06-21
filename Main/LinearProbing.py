# linear probing and quadratic probing ,chainig 
class Dictionary : 
    def __init__(self,size) : 
        self.size = size
        self.slots = [None]*self.size   #keys
        self.data = [None]*self.size    #values
    def hashfunction(self,key) :
        return abs(hash(key))%self.size
    def put(self,key,value) :
        hash_value = self.hashfunction(key)
        if self.slots[hash_value] == None :
            self.slots[hash_value] = key
            self.data[hash_value] = value
        else :
            if self.slots[hash_value] == key :
                self.data[hash_value] = value
            else :
                next_slot = self.rehash(hash_value)
                while self.slots[next_slot] != None and self.slots[next_slot] != key :
                    next_slot = self.rehash(next_slot)
                if self.slots[next_slot] == None :
                    self.slots[next_slot] = key
                    self.data[next_slot] = value
                else :
                    self.data[next_slot] = value
    def rehash(self,oldhash) :
        return (oldhash+1)%self.size
    def get(self,key) :
        startslot = self.hashfunction(key)
        data = None
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop :
            if self.slots[position] == key :
                found = True
                data = self.data[position]
            else :
                position = self.rehash(position)
                if position == startslot :
                    stop = True
        return data
    def __getitem__(self,key) :
        return self.get(key)
    def __setitem__(self,key,value) :
        self.put(key,value)
    def __str__(self) :
        return str(self.slots) + '\n' + str(self.data)
        
    def __len__(self) :
        return self.size



a = Dictionary(5)
a.put('char1','Harry')
a.put('char2','Ron')
a.put('char3','Hermione')
a.put('char4','Dumbledore')
a.put('char5','Voldemort')


print(len(a))

print(a)

print(a['char1'])
print(a.get('char1'))
print(a.get('char2'))
print(a.get('char3'))
print(a.get('char4'))
print(a.get('char5'))

print(a.__str__())



