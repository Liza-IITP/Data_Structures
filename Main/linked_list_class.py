class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Pointer to the next node in the list

class LinkedList:
    def __init__(self):
        self.head = None  # Initially, the linked list is empty
    
    # Method to insert a node at the head (beginning) of the list
    def insert_head(self, data):
        new_node = Node(data)  # Create a new node
        new_node.next = self.head  # Point the new node to the current head
        self.head = new_node  # Make the new node the head of the list
    
    # Method to insert a node at a given index
    def insert_at_index(self, data, index):
        if index < 0 or index > self.length():
            print("Index out of bounds")
            return
        
        new_node = Node(data)
        if index == 0:
            self.insert_head(data)  # If inserting at index 0, use insert_head
            return
        
        current = self.head
        count = 0
        while current and count < index - 1:
            current = current.next
            count += 1
        
        new_node.next = current.next  # Link the new node to the next node
        current.next = new_node  # Link the previous node to the new node
    
    # Method to update a node at a specific index
    def update_node(self, value_to_update, index):
        current = self.head
        count = 0
        while current:
            if count == index:
                current.data = value_to_update  # Update the node's value
                return True  # Return True to indicate that the node was updated
            current = current.next
            count += 1
        return False  # Return False if the index is out of range
    
    # Method to print the Linked List
    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")  # End of list
    
    # Method to get the length of the Linked List
    def length(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

# Example usage
ll = LinkedList()

# Insert at head
ll.insert_head(10)
ll.insert_head(20)
ll.insert_head(30)

print("List after inserting at head:")
ll.print_list()

# Insert at a specific index (insert 15 at index 1)
ll.insert_at_index(15, 1)

print("List after inserting 15 at index 1:")
ll.print_list()

# Update a node (update value at index 2)
ll.update_node(100, 2)

print("List after updating node at index 2 to 100:")
ll.print_list()

# Length of the linked list
print("Length of Linked List:", ll.length())

