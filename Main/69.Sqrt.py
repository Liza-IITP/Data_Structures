class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x//2+2) :
            if i**2<=x<(i+1)**2 :
                return i


# test the function
x = 8
sol = Solution()
print(sol.mySqrt(x)) # 2
   
x = 4
sol = Solution()
print(sol.mySqrt(x)) # 2

x = 1
sol = Solution()
print(sol.mySqrt(x)) # 1

x = 0
sol = Solution()
print(sol.mySqrt(x)) # 0

x = 2
sol = Solution()
print(sol.mySqrt(x)) # 1

# OPTMISE THE CODE TO REDUCE TC AND SC

class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x 
        left = 1
        right = x//2
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                left = mid + 1
            else:
                right = mid - 1
        return right
    # test the function
x = 3
sol = Solution()
print(sol.mySqrt(x)) # 2

