from collections import deque
def generate_square(n):
    """
    Function to return a square pattern of '*' of side n as a list of strings.
    
    Parameters:
    n (int): The size of the square.
    
    Returns:
    list: A list of strings where each string represents a row of the square.
    """
    # Your code here
    list_op=[]
    for i in range(0,n):
        list_op.append("*"*n)
    print(list_op)
# print(generate_square(5))

def generate_hollow_square(n):
    """
    Function to return a hollow square pattern of '*' of side n as a list of strings.
    
    Parameters:
    n (int): The size of the square.
    
    Returns:
    list: A list of strings where each string represents a row of the hollow square.
    """
    list_op = []
    for i in range(0,n):
        if i == 0 or i == n-1:
            list_op.append("*"*n)
        else:
            list_op.append("*" + " "*(n-2) + "*")
        
    return list_op

print(generate_hollow_square(20))


def generate_pyramid(n):
    """
    Function to return a pyramid pattern of '*' of side n as a list of strings.
    
    Parameters:
    n (int): The number of rows in the pyramid.
    
    Returns:
    list: A list of strings where each string represents a row of the pyramid.
    """
    # Your code here
    list_op=[]
    x= 2*n-1
    for i in range(0,n):
        list_op.append(" "*(x//2-i) + "*"*(2*i+1) + " "*(x//2-i))
    return list_op
print(generate_pyramid(5))
# for reversing the algorithm
    # list_op=[]
    # x= 2*n-1
    # for i in range(1,n+1) : 
    #     list_op.append(" "*((x-(2*i-1))//2)+"*"*(2*i-1)+" "*((x-(2*i-1))//2))
    # list_op.reverse()
    # return list_op

# print(generate_pyramid(5))
def generate_f(n):
    list_op=[]
    for i in range(1,n+1):
        list_op.append(str(i)*i)
            
    return list_op

# print(generate_f(5))
n = 5
counter = 1
list_  =[]
for i in range(n):
    # join the list of numbers to form a string
    list_.append(
        " ".join([str(a) for a in range(counter, counter + 1 + i)])
    )
    counter = counter + i + 1
print(list_)

# [[1] [2 3] [4 5 6]] = list       

def generate_rhombus(n):

    list_op = []
    x = 2*n-1
    for i in range(1,n+1):
        list_op.append(" "*(x//2-i+1) + "*"*i + " "*(x//2-i+1))
    for i in range(n-1,0,-1):
        list_op.append(" "*(x//2-i+1) + "*"*i + " "*(x//2-i+1))
    return list_op
print(generate_rhombus(5))

def merge_dicts_with_overlapping_keys(dicts):
    # Your code goes here
    dict_new={}
    for i in dicts : 
        for j in i.keys() :
            if j in dict_new.keys() :
                dict_new[j]= dict_new[j]+i[j]
            else : 
                dict_new.update(i)
    return dict_new

''' Asked in Companies:

Google

Amazon

Facebook

Microsoft

Description:
You are given the root of an N-ary tree. Your task is to write a function to count the total number of nodes in the tree.

An N-ary tree is a tree in which a node can have at most N children.

Input Parameters:

root (Node): The root node of the N-ary tree.

Output:

An integer representing the total number of nodes in the tree.

Example:

Input:
      1
    / | \
   2  3  4
      |
      5
 
Output: 5
 
 
Input:
      1
    / | \ \
   2  3  4  5
 
Output: 5


Disclaimer:

This Udemy coding exercise is still in development, so some advanced complexities might not be fully checked. Please use it primarily for basic code validation.



LeetCode Link:
There is no direct matching LeetCode problem, but this problem is inspired by tree traversal and counting problems.''' 
def countnodes(root) : 
    count = 0 
    if root == None : 
        return 0
    for child in root.children : 
        count += countnodes(child) 
    return count + 1

# Test it with the provided example
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

root = Node(1)

child1 = Node(2)

child2 = Node(3)

child3 = Node(4)

child4 = Node(5)

root.children = [child1, child2, child3, child4]

print(countnodes(root))  # Output: 5

def largestinrow(root) : 
    if root == None : 
        return []
    max_row = 0 
    max_row_values = []
    queue = deque()
    queue.append(root)
    while len(queue)!= 0 :
        size = len(queue)
        max_row = max(max_row, size)
        max_row_values.append(max([node.val for node in queue]))
        for i in range(size) : 
            node = queue.popleft()
            for child in node.children : 
                queue.append(child) 
    return max_row_values

# Test it with the provided example
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

root = Node(1)

child1 = Node(2)
child2 = Node(3)

child3 = Node(4)

child4 = Node(5)

root.children = [child1, child2, child3, child4]

print(largestinrow(root))  # Output: [1, 2, 3, 4, 5] 
# op = 1 5 
