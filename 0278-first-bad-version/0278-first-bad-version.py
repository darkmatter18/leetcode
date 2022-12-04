import math

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return self.check_bad(0, n)
        
        
    def check_bad(self, s:int, n:int):
        mid = math.ceil((s + n)/2)
        print(s, mid, n)
        if mid == n:
            return n
        if isBadVersion(mid):
            # s to mid
            return self.check_bad(s, mid)
        else:
            # mid to n
            return self.check_bad(mid, n)