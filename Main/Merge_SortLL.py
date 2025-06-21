# EG. 3-> 2 -> 10 -> 5 -> 8 -> 12 -> None 
# Output: 2 -> 3 -> 5 -> 8 -> 10 -> 12 -> None 
# To do it using Merge Sort 
# Note that in merge sort for 
# list we used to split and 
# then combine all fractions in ascending order : 

class listNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    
class Solution : 
    def getMid(self, head):
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    def merge(self, l1 : listNode, l2 : listNode ) -> listNode :

        dummy = listNode()
        current = dummy
        while l1 and l2 :
            if l1.val < l2.val :
                current.next = l1
                l1 = l1.next
            else :
                current.next = l2
                l2 = l2.next
            current = current.next
        if l1 :
            current.next = l1
        if l2 :
            current.next = l2 
        return dummy.next
        # To understand the above code of merging : 
        # eg. 2->3->10->None and 5->8->12->None
        # dummy = listNode() => None
        # current = dummy => None
        # while l1 and l2 :
        # if l1.val < l2.val : => 2 < 5
        # current.next = l1 => None -> 2 -> None
        # l1 = l1.next => 3->10->None
        # current = current.next => 2->None
        # if l1.val < l2.val : => 3 < 5
        # current.next = l1 => 2->3->None
        # l1 = l1.next => 10->None
        # current = current.next => 3->None
        # if l1.val < l2.val : => 10 > 5
        # current.next = l2 => 3->5->None
        # l2 = l2.next => 8->12->None
        # current = current.next => 5->None
        # if l1 : => False
        # if l2 : => True
        # current.next = l2 => 5->8->12->None
        # return dummy.next => 2->3->5->8->10->12->None
        # Why didn't we retuen dummy here ? 
        # Because we need to return the sorted list instead of None -> 2 -> 3 -> 5 -> 8 -> 10 -> 12 -> None
        # So we return dummy.next which is 2 -> 3 -> 5 -> 8 -> 10 -> 12 -> None


    def sortlist(self,head : listNode ) -> listNode :
        if not head or not head.next :
            return head
        # split the list into two halfs 
        left = head 
        right= self.getMid(head) 
        tmp = right.next
        right.next = None 
        right = tmp 
        left = self.sortlist(left)
        right = self.sortlist(right)
        return self.merge(left, right)
        # To understand the above code : 
        # eg. 3->2->10->5->8->12->None
        # left = head 
        # right = getmid(head) => 10 
        # tmp = right.next => 5
        # right.next = None => 10->None
        # right = tmp => 5->8->12->None
        # left = sortlist(left) => 2->3->10->None
        # right = sortlist(right) => 5->8->12->None
        # return merge(left, right) => 2->3->5->8->10->12->None  

# Test the function
# Create a linked list
head = listNode(3)
head.next = listNode(2)
head.next.next = listNode(10)
head.next.next.next = listNode(5)
head.next.next.next.next = listNode(8)
head.next.next.next.next.next = listNode(12)

# Create an instance of Solution class  
sol = Solution()
# Sort the linked list
head = sol.sortlist(head)
# Print the sorted linked list
while head:
    print(head.val, end = " -> ")
    head = head.next
print("None")
# Output : 2 -> 3 -> 5 -> 8 -> 10 -> 12 -> None


     

