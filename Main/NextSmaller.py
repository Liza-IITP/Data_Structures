def next_smaller_elements(arr):
    """
    Function to find the next smaller element for each element in the array.
    :param arr: List[int] -> List of integers
    :return: List[int] -> List of next smaller elements for each element
    """
    # TODO: Implement this function
    n = len(arr) 
    result = [-1]*n
    stack = [] 
    for i in range(n):
        while stack!=[] and arr[stack[-1]]>arr[i] : 
                index = stack.pop()
                result[index] = arr[i]
        stack.append(i)
    return result
