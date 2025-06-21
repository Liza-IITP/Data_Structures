class DoubleCircularNode : 
    def __init__(self,data) : 
        self.data = data
        self.next = None
        self.prev = None
class DoubleCircularLL : 
    def __init__(self) : 
        self.head = None 
        self.tail = None 
    def insertAtEnd(self,data) :
        newNode = DoubleCircularNode(data)
        if self.head == None : 
            self.head = newNode
            self.tail = newNode
            newNode.next = newNode
            newNode.prev = newNode
        else : 
            self.tail.next = newNode
            newNode.prev = self.tail
            newNode.next = self.head
            self.head.prev = newNode
            self.tail = newNode
    def insertAtBegin(self,data) :
        newNode = DoubleCircularNode(data)
        if self.head == None : 
            self.head = newNode
            self.tail = newNode
            newNode.next = newNode
            newNode.prev = newNode
        else : 
            newNode.next = self.head
            self.head.prev = newNode
            newNode.prev = self.tail
            self.tail.next = newNode
            self.head = newNode
    def insertAtPos(self,data,pos) :
        newNode = DoubleCircularNode(data)
        if self.head == None : 
            self.head = newNode
            self.tail = newNode
            newNode.next = newNode
            newNode.prev = newNode
        elif pos == 0 :
            self.insertAtBegin(data)
        else :
            currentNode = self.head
            count = 0
            while count < pos - 1 and currentNode.next != self.head :
                currentNode = currentNode.next
                count += 1
            newNode.next = currentNode.next
            newNode.prev = currentNode
            currentNode.next.prev = newNode
            currentNode.next = newNode
    def deleteAtBegin(self) :
        if self.head == None : 
            print("List is Empty")
        elif self.head == self.tail :
            self.head = None
            self.tail = None
        else : 
            self.head = self.head.next
            self.head.prev = self.tail
            self.tail.next = self.head
    def deleteAtEnd(self) :
        if self.head == None : 
            print("List is Empty")
        elif self.head == self.tail :
            self.head = None
            self.tail = None
        else : 
            self.tail = self.tail.prev
            self.tail.next = self.head
            self.head.prev = self.tail 
    def deleteAtPos(self,pos) :
        if self.head == None : 
            print("List is Empty")
        elif pos == 0 :
            self.deleteAtBegin()
        else : 
            currentNode = self.head
            count = 0
            while count < pos - 1 and currentNode.next != self.head :
                currentNode = currentNode.next
                count += 1
            currentNode.next = currentNode.next.next
            currentNode.next.prev = currentNode
    def display(self) :
        if self.head == None : 
            print("List is Empty")
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                print(currentNode.data,end = " ")
                currentNode = currentNode.next
            print(currentNode.data)
            print()
    def displayReverse(self) :
        if self.head == None : 
            print("List is Empty")
        else : 
            currentNode = self.tail
            while currentNode.prev != self.tail :
                print(currentNode.data,end = " ")
                currentNode = currentNode.prev
            print(currentNode.data)
            print()
    def search(self,data) :
        if self.head == None : 
            print("List is Empty")
        else : 
            currentNode = self.head
            count = 0
            while currentNode.next != self.head :
                if currentNode.data == data :
                    return count
                currentNode = currentNode.next
                count += 1
            if currentNode.data == data :
                return count
            return -1
    def reverse(self) :
        if self.head == None : 
            print("List is Empty")
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                currentNode.next,currentNode.prev = currentNode.prev,currentNode.next
                currentNode = currentNode.prev
            currentNode.next,currentNode.prev = currentNode.prev,currentNode.next
            self.head,self.tail = self.tail,self.head 
    def sort(self) :
        if self.head == None : 
            print("List is Empty")
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                temp = currentNode.next
                while temp != self.head :
                    if currentNode.data > temp.data :
                        currentNode.data,temp.data = temp.data,currentNode.data
                    temp = temp.next
                currentNode = currentNode.next
    def merge(self,l2) :
        if self.head == None : 
            self.head = l2.head
            self.tail = l2.tail
        else : 
            self.tail.next = l2.head
            l2.head.prev = self.tail
            self.tail = l2.tail
            l2.head = None
            l2.tail = None
    def split(self) :
        if self.head == None : 
            print("List is Empty")
        else : 
            slow = self.head
            fast = self.head
            while fast.next != self.head and fast.next.next != self.head :
                slow = slow.next
                fast = fast.next.next
            if fast.next != self.head :
                fast = fast.next
            l2 = DoubleCircularLL()
            l2.head = slow.next
            l2.tail = self.tail
            slow.next = self.head
            self.tail = slow
            l2.head.prev = l2.tail
            l2.tail.next = l2.head
            return l2
    def isCircular(self) :
        if self.head == None : 
            return False
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                currentNode = currentNode.next
            if currentNode.next == self.head :
                return True
            return False
    def isPalindrome(self) :
        if self.head == None : 
            return False
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                currentNode = currentNode.next
            temp = self.head
            while temp != currentNode :
                if temp.data != currentNode.data :
                    return False
                temp = temp.next
                currentNode = currentNode.prev
            return True
    def isSorted(self) : 
        if self.head == None : 
            return False
        else : 
            currentNode = self.head
            while currentNode.next != self.head :
                if currentNode.data > currentNode.next.data :
                    return False
                currentNode = currentNode.next
            return True
        