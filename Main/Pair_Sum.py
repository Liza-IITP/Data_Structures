# Finding a pair with given sum in a sorted arr 167
def fd(arr, sum) : 
    if len(arr) == 0 : return False
    left = 0 
    right = len(arr) - 1
    if left == right : 
        return False 
    while left < right :
        if arr[left] + arr[right] == sum : 
            return f"indices are : {left} , {right} WHICH ADD UPTO {sum}"
        elif arr[left] + arr[right] < sum :
            left+=1
        elif arr[left] + arr[right] > sum :
            right-=1 
    return False
 # Return None if no triplet is found

# Sum of triplet being 0 
def threeSum(nums):
        nums.sort()  # Sort the array first
        result = []
        n = len(nums)

        for i in range(n):
            # Skip duplicates for the current element
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # Use two pointers for the remaining part of the array
            target = -nums[i]
            left, right = i + 1, n - 1

            while left < right:
                current_sum = nums[left] + nums[right]

                if current_sum == target:
                    result.append([nums[i], nums[left], nums[right]])

                    # Move pointers and skip duplicates
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

                elif current_sum < target:
                    left += 1
                else:
                    right -= 1

        return result


# Testing the function
print(threeSum([-2,-7,-4,-10,9,5,1,3]))  
# Closest Sum
def threeSumClosest( nums, target: int) -> int:
        nums.sort()  # Sort the array
        closest_sum = float('inf')  # Initialize the closest sum as infinity
        
        for i in range(len(nums) - 2):
            # Skip duplicate elements to avoid redundant work
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                
                # Update the closest sum if the current sum is closer to the target
                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum
                
                # If the current sum is less than the target, move the left pointer to the right
                if current_sum < target:
                    left += 1
                # If the current sum is greater than the target, move the right pointer to the left
                elif current_sum > target:
                    right -= 1
                else:
                    # If the current sum is exactly equal to the target, return the sum immediately
                    return current_sum

        return closest_sum