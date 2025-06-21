class Solution:
    def climbStairs(self, n: int) -> int:
        climbstairs = [1]*(n+1)
        climbstairs[0]=1
        climbstairs[1]=1 
        
        for i in range(2,n+1) :
            climbstairs[i]= climbstairs[i-1]+climbstairs[i-2]

        return climbstairs[n]

# Test the solution
n = 6
sol = Solution()
output = sol.climbStairs(n)
print(output)

# Let's optimise it for space complexity 
class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        first = 1
        second = 2
        for i in range(3,n+1):
            third = first + second
            first = second
            second = third
        return second