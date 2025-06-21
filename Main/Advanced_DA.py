# For more adv func move to line 70
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

    def sort(self) :
        for i in range(self.n) :
            for j in range(i+1, self.n) :
                if self.A[i]>self.A[j] :
                    self.A[i], self.A[j] = self.A[j], self.A[i] 

    def minimum(self) :
        if self.n==0 :
            return IndexError('Index out of range')
        ans = self.A[0]
        for i in range(1, self.n) :
            if self.A[i]<ans :
                ans = self.A[i]
        return ans
    def maximum(self) :
        if self.n==0 :
            return IndexError('Index out of range')
        ans = self.A[0]
        for i in range(1, self.n) :
            if self.A[i]>ans :
                ans = self.A[i]
        return ans
    def sum(self) :
        ans = 0
        for i in range(self.n) :
            ans+=self.A[i]
        return ans
    def extend(self, other) :
        for i in range(other.n) :
            self.append(other.A[i])

    def negativeidexing(self,index) :
        if index<0 or index>=self.n :
            return IndexError('Index out of range')
        return self.A[self.n+index]
    # slicing helps to get the elements from start to end with step size
    def slicing(self,start,end,step) :
        if start<0 or start>=self.n or end<0 or end>=self.n :
            return IndexError('Index out of range')
        result = mylist()
        for i in range(start, end, step) :
            result.append(self.A[i])
        return result
    def merge(self, other):
        result=[]
        for i in self :
            result.append(i)
        for i in other :
            result.append(i)
        return result
     