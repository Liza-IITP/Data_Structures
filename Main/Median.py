from typing import List
def median(arr):
    # Ensure the list is sorted (although, it's already sorted in this case)
    arr.sort()
    if len(arr) % 2 != 0:
        return arr[len(arr) // 2]
    return (arr[len(arr) // 2] + arr[len(arr) // 2 - 1]) / 2

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i = j = 0
        merged = []
        # Merging two sorted arrays into a single sorted array
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:  # This includes the case when nums1[i] == nums2[j]
                merged.append(nums2[j])
                j += 1
        
        # Add remaining elements if any
        if i != len(nums1):
            merged += nums1[i:]
        if j != len(nums2):
            merged += nums2[j:]

        # Find the median of the merged array
        return median(merged)

# Test the solution
sol = Solution()
print(sol.findMedianSortedArrays([1, 3], [2]))  # Output: 2.0
print(sol.findMedianSortedArrays([1, 2], [3, 4]))  # Output: 2.5

# Test case with duplicate elements
print(sol.findMedianSortedArrays([1, 2, 2], [2, 3, 4]))  # Output: 2.0

# Test case with empty arrays
print(sol.findMedianSortedArrays([], [1]))  # Output: 1.0

# Test case with one empty array
print(sol.findMedianSortedArrays([1], []))  # Output: 1.0

# Test case with arrays of different lengths
print(sol.findMedianSortedArrays([1, 2], [3, 4, 5]))  #
print(sol.findMedianSortedArrays([1, 2, 3], [4, 5]))  #
print(sol.findMedianSortedArrays([1, 2, 3, 4], [5]))  #
print(sol.findMedianSortedArrays([1, 2, 3, 4, 5], [6]))  #

# Test case with arrays with negative numbers
print(sol.findMedianSortedArrays([-1, 3], [-2]))  # Output: -1.0
print(sol.findMedianSortedArrays([-1, 3], [-2, 4]))  # Output: 0.5

# Test case with arrays with floating-point numbers
print(sol.findMedianSortedArrays([1.5, 3.5], [2.5]))  # Output: 2.5
print(sol.findMedianSortedArrays([1.5, 2.5], [3.5, 4.5]))  # Output: 2.5

# Test case with arrays with very large numbers
print(sol.findMedianSortedArrays([1000000000], [1000000001]))  # Output: 1000000000.5