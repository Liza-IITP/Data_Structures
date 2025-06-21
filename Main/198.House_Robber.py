class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])
        for i in range(2,len(nums)):
            dp[i] = max(dp[i-1],dp[i-2]+nums[i])
        return dp[-1]
        

# test the function

print(Solution().rob([1,2,3,1])) # Expected: 4
print(Solution().rob([2,7,9,3,1])) # Expected: 12
print(Solution().rob([1])) # Expected: 1
print(Solution().rob([0])) # Expected: 0
print(Solution().rob([1,1,1,1,1])) # Expected: 3