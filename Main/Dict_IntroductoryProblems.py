def intersection(arr1, arr2):   
    for i in arr1: 
        if i in arr2:
            arr1.remove(i)
            arr2.remove(i)
            print(i)
    print("Removing Intersecting elements :")
    return arr1, arr2
        

arr1 = [1, 2, 3, 2, 5]
arr2 = [2, 3, 4, 2, 6]
print(intersection(arr1, arr2))

# DUPLICATE
def duplicatecheck(arr) :
    for i in range(len(arr))  :
        if arr[i] in arr[i+1:] or arr[i] in arr[:i] :
            print(arr[i])
    return 

arr = [1, 2, 3, 2, 5]
print(duplicatecheck(arr))

# FIRST NON REPEATING elements
def non_repeating(arr) :
    for i in range(len(arr)) :
        if arr[i] not in arr[i+1:] and arr[i] not in arr[:i] :
            print(arr[i])
            break
    return
 
arr = [5, 2, 3, 2, 5]
print(non_repeating(arr))

arr =[5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 7] 
hashmap = {}
for i in arr :
    if i not in hashmap.keys() :
        count_i = 0
        hashmap[i] = count_i
    count_i+=1 
    hashmap[i] = count_i
print(hashmap)
even = odd = 0
for k in hashmap.values() :
    if k%2==0 :
        even+=1 
    else :
        odd+=1
print(tuple([odd,even]))

strs= ["eat", "tea", "tan", "ate", "nat", "bat"]
lis= []
result = []
for i in strs : 
    result.append(sorted(i))

    
from collections import defaultdict

def groupAnagrams(strs):
    # Create a defaultdict where the key is the sorted word and the value is the list of anagrams
    anagram_map = defaultdict(list)
    
    for word in strs:
        # Sort the word and use the sorted word as the key
        sorted_word = ''.join(sorted(word))
        anagram_map[sorted_word].append(word)
    
    # Return the values (groups of anagrams)
    return list(anagram_map.values())

print(groupAnagrams(strs))

''' Input:
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 
Output:
[
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]
 
 
Input:
strs = [""]
 
Output:
[
  [""]
]
 
 
Input:
strs = ["a"]
 
Output:
[
  ["a"]
]
'''

def most_frequent_number(arr):
    """
    Function to find and return the number that occurs the most times in the array.
    In case of ties, return the number that appears first in the array.
    
    :param arr: List[int] -> The input list of integers
    :return: int -> The most frequent number in the array
    """
    # TODO: Implement the logic using a hashmap (dictionary)
    hashmap ={}
    for i in arr :
        if i in hashmap :
            hashmap[i]+=1
        else :
            hashmap[i]=1 
    max = 0
    for i in hashmap.values() :
        if i>max :
            max = i 
    for i in hashmap.keys() :
        if hashmap[i]==max :
            return i

arr = [1, 3, 1, 3, 2, 1]
print(most_frequent_number(arr))  # Output: 1

def greatest_product_equal_to_element(arr):
    """
    Function to find the greatest number in the array that is equal to the product of two different elements.
    
    :param arr: List[int] -> The input list of integers
    :return: int -> The greatest number in the array that is equal to the product of two different elements
    """
    '''Input: ARR = [1, 2, 3, 6, 12]
Output: 12
Explanation: The number 12 is present in the array and it is the product of 2 and 6.
 
Input: ARR = [4, 2, 3, 8]
Output: 8'''
    # TODO: Implement the logic using a hashmap approach
    result=[]
    for i in arr :
        for j in arr :
            if i!=j and i*j in arr :
                result.append(i*j)
    return max(result)

arr = [1, 2, 3, 6, 12]
print(greatest_product_equal_to_element(arr))  # Output: 12
def sum(nums,target) :
    for i in nums :
            if target==2*i and target-i in nums[nums.index(i)+1:] : 
                return [nums.index(i),nums.index(i)+(nums[nums.index(i)+1:]).index(target-i)+1] 
            if target-i!=i and target-i in nums[nums.index(i)+1:]: 
                return [nums.index(i),nums.index(target-i)]

print(sum([2, 7, 11, 15], 9))