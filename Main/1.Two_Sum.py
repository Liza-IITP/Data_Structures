def twoSum(nums, target) :
    for i in nums :
        complement = target - i
        l = nums[nums.index(i)+1:]
        if complement in  l:
            if i == complement:
                return [nums.index(i),nums.index(i)+l.index(complement)+1]
        return [nums.index(i), nums.index(complement)]
        
print(twoSum([2, 7, 11, 15], 9))
print(twoSum([3,2,4],6))       
print(twoSum([3,3], 6))
def twoSum2(nums,target) :
    d = {}
    for i, num in enumerate(nums):
        if target - num in d:
            return [d[target - num], i]
        d[num] = i
print(twoSum2([2, 7, 11, 15], 9))
print(twoSum2([3,2,4],6))

print(twoSum2([3,3], 6))

def sumbetter(nums,target) : 
    for i in nums :
        if target==2*i and target-i in nums[nums.index(i)+1:] : 
            return [nums.index(i),nums.index(i)+(nums[nums.index(i)+1:]).index(target-i)+1] 
        if target-i!=i and target-i in nums[nums.index(i)+1:]: 
            return [nums.index(i),nums.index(target-i)]
        
print(sumbetter([2, 7, 11, 15], 9))
print(sumbetter([3,2,4],6))
print(sumbetter([3,3], 6))
