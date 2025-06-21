def f(nums):
    sum =0 
    for i in range(len(nums)) :
        sum+=nums[i]
        nums[i] = sum
    return nums

print(f([1,2,3,4])) # [1,3,6,10]