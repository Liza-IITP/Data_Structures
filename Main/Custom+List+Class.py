import ctypes

class CustomList:
    def __init__(self):
        initialCapacity = 1
        self.capacity =  initialCapacity
        self.size = 0
        self.array = self.__create_array(self.capacity)

    def __create_array(self,capacitiy):
        # Create a new referential array with given capacity
        return (capacitiy*ctypes.py_object)()
    
    def __resize(self,new_capacity):
        new_array = self.__create_array(new_capacity)
        for i in range(self.size):
            new_array[i] = self.array[i]
        
        self.array = new_array # Replace the old Array
        self.capacity = new_capacity


    def append(self,item):
        if(self.size == self.capacity):
            self.__resize(2*self.capacity)

        self.array[self.size] = item
        self.size+=1
    
    def __len__(self):
        
        return self.size
    
    def __str__(self):
        output = ''
        for i in range(self.size):
            output = output + str(self.array[i]) + ','
        
        return '[' + output[:-1] + ']'
    
    def pop(self):
        if(self.size == 0):
            return ('Empty List , IndexError: pop from empty list')

        
        popped_item = self.array[self.size-1]
        self.size = self.size -1
        return popped_item
    
    def __getitem__(self,index):
        if(index >=0 and index < self.size):
            return self.array[index]
        else:
            return "Index Error : Invalid index"
        
    def clear(self):
        self.size=0

    def insert(self,position,element):
        # Position will  be inside only
        if(self.size == self.capacity):
            self.__resize(2*self.capacity)
        
        for index in range(self.size,position,-1): 
            self.array[index] = self.array[index-1]
        
        self.array[position] = element
        self.size +=1

    def remove(self,element):
        for index in range(self.size):
            if(self.array[index] == element):
                for i in range(index,self.size-1):
                    self.array[i] = self.array[i+1]
                
                self.size = self.size -1
                return True
        
        return False
    
    def index(self, element):     
        for index in range(self.size):
            if(self.array[index] == element):
                return index
        return -1
    
    def count(self, element):
        count = 0
        for index in range(self.size):
            if(self.array[index] == element):
                count+=1
        return count
    
    def extend(self, other_list):
        for item in other_list:
            self.append(item)
    
    def reverse(self):
        start = 0
        end = self.size - 1
        while start < end:
            self.array[start], self.array[end] = self.array[end], self.array[start]
            start += 1
            end -= 1


myList = CustomList()
myList.append(1)
myList.append(2)
myList.append(3)
myList.append(4)
myList.append(5)
myList.append(6)
print(myList)
myList.insert(1,100)
print(myList)
print(myList.pop())
print(myList)
getitem = myList.__getitem__(1)
print(getitem)
print(len(myList))
myList.remove(100)
print(myList)
print(myList.index(3))
print(myList.count(3))
myList.extend([5,6,7])
print(myList)

# implement str function 
myList.__str__()

print(myList)
myList.clear()
print(myList)
