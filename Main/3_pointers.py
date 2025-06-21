# Sort Colours 75 
# Red 0 White 1 Blue 2 
def sortColors(nums):
    # Initialize pointers
    low, mid, high = 0, 0, len(nums) - 1
    
    # Iterate through the array
    while mid <= high:
        if nums[mid] == 0:
            # Swap 0 to the left region
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            # Leave 1 in the middle region
            mid += 1
        else:  # nums[mid] == 2
            # Swap 2 to the right region
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1
    
    return nums

   
print(sortColors([2,0,2,1,1,0]))





# Merge intervals 56
def merge(intervals):
    # Custom sort function to sort intervals by their start times
    def sort(intervals):
        for i in range(len(intervals)):
            for j in range(i + 1, len(intervals)):
                if intervals[i][0] > intervals[j][0]:
                    intervals[i], intervals[j] = intervals[j], intervals[i]
        return intervals

    # Step 1: Sort intervals
    intervals = sort(intervals)

    # Step 2: Initialize pointers and result list
    i = 0
    result_list = []

    # Step 3: Merge intervals using two pointers
    while i < len(intervals):
        current_start = intervals[i][0]
        current_end = intervals[i][1]

        # Merge overlapping intervals
        while i + 1 < len(intervals) and intervals[i + 1][0] <= current_end:
            current_end = max(current_end, intervals[i + 1][1])
            i += 1

        # Add the merged interval to the result list
        result_list.append([current_start, current_end])
        i += 1

    return result_list


intervals = [[1, 3], [2, 6],[8,10], [18, 20], [15, 18]]
print(merge(intervals)) 

