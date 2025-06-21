import ctypes 
class mylist :
    def __init__(self):
        self.n = 0
        self.size = 1
        self.A = self.make_array(self.size) 
    def make_array(self, size):
        return (size * ctypes.py_object)()
    # this code createsc type array static but referential with size of size 
    def __len__(self):
        return self.n
    # it'll return no. of elements
    def __resize(self,newcapacity) :
        B = self.make_array(newcapacity)
        for i in range(self.n):
            B[i] = self.A[i]
        self.A = B
        self.size = newcapacity
    def append(self, item):
        if self.size==self.n :
            self.__resize(2*self.size)
        self.A[self.n] = item
        self.n+=1
    def __str__(self) :
        result = ""
        for i in range(self.n) :
            result += str(self.A[i]) + ","
        return '['+ result[:-1]+']'
    def __getitem__(self, index):
        if index<0 or index>=self.n :
            return IndexError('Index out of range')
        return self.A[index]
    def pop(self) :
        if self.n==0 :
            return IndexError('Index out of range')
        ans = self.A[self.n-1]
        self.n-=1
        return ans
    def clear(self) :
        self.n = 0
        self.size = 1
        self.A = self.make_array(self.size)
    def find(self, item) :
        for i in range(self.n) :
            if self.A[i]==item :
                return i
        return -1
    def insert(self, index, item) :
        if self.n==self.size :
            self.__resize(2*self.size) 
        for i in range(self.n, index, -1) :
            self.A[i]=self.A[i-1]
        self.A[index] = item
        self.n+=1

    def delete(self, index) :
        if index<0 or index>=self.n :
            return IndexError('Index out of range')
        for i in range(index, self.n-1) :
            self.A[i] = self.A[i+1]
        self.n-=1

    def remove(self, item) :
        index = self.find(item)
        if index==-1 :
            return IndexError('Item not found')
        self.delete(index)

        
# testing the code

l = mylist()
l.append(1)
l.append(2)
l.append(3)
print(l)
print(l.pop())
print(l)
l.clear()
print(l)
l.append(1)
l.append(2)
l.append(3)
print(l)
print(l.find(2))
l.insert(1, 5)
print(l)
l.delete(1)
print(l)
l.remove(3)
print(l)
print(len(l))
