from collections import deque
def minCostClimbingStairs(cost):
    if len(cost)==0 :
        return 0
    if len(cost)==1:
        return cost[0]
    dp = [0] * (len(cost)+1)
    dp[0] = cost[0]
    dp[1] = cost[1]
    for i in range(2,len(cost)):
        dp[i] = cost[i] + min(dp[i-1],dp[i-2])
    return min(dp[len(cost)-1],dp[len(cost)-2])

            
        
    
# Time Complexity: O(n)
# Space Complexity: O(n)
# Runtime: 60 ms, faster than 82.75%

# Test cases
cost = [10, 15, 20]

print(minCostClimbingStairs(cost))
# Output: 15
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]

print(minCostClimbingStairs(cost))
# Output: 6



    