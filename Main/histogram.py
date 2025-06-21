def largestRectangleArea(heights):
    """
    Function to calculate the largest rectangle area in a histogram.
    :param heights: List[int] -> List of bar heights
    :return: int -> Maximum rectangle area
    """
    n = len(heights)
    max_area = 0
    for i in range(n):
        left = i
        right = i
        
        # Expand to the left as long as the height is greater than or equal to the current height
        while left > 0 and heights[left - 1] >= heights[i]:
            left -= 1
        
        # Expand to the right as long as the height is greater than or equal to the current height
        while right < n - 1 and heights[right + 1] >= heights[i]:
            right += 1
        
        # Calculate the area of the rectangle with heights[i] as the smallest height
        width = right - left + 1
        area = width * heights[i]
        max_area = max(max_area, area)
    
    return max_area

# Driver code
heights = [2, 1, 5, 6, 2, 3]
print("Largest Rectangle Area:", largestRectangleArea(heights))

# OPTIMIZED STACK CODE 
def largestRectangleArea(heights):
    """
    Find the area of the largest rectangle in the histogram.
    :param heights: List[int] -> List of bar heights
    :return: int -> Maximum rectangle area
    """
    # Initialize the stack and the maximum area
    stack = []  # To store indices of the histogram bars
    max_area = 0  # Variable to track the largest rectangle area
    index = 0  # Current index in the histogram

    # Iterate through the histogram bars
    while index < len(heights):
        # If the stack is empty or the current bar is taller than the top of the stack
        if not stack or heights[index] >= heights[stack[-1]]:
            stack.append(index)  # Push the current index onto the stack
            index += 1
        else:
            # Pop the top of the stack (smallest bar so far)
            top_of_stack = stack.pop()
            # Calculate the area with the popped bar as the smallest height
            width = index if not stack else index - stack[-1] - 1
            area = heights[top_of_stack] * width
            # Update the maximum area
            max_area = max(max_area, area)

    # Process the remaining bars in the stack
    while stack:
        top_of_stack = stack.pop()
        width = index if not stack else index - stack[-1] - 1
        area = heights[top_of_stack] * width
        max_area = max(max_area, area)

    return max_area

print(largestRectangleArea([2, 1, 5, 6, 2, 3]))  # Output: 10

