'''
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
'''
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # First we got to do binary search to find the position. 
        l = 0
        r = len(nums) - 1
        mid = int(l+(r-l)/2)
        while(l <= r):
            mid = int(l+(r-l)/2)
            if(nums[mid] == target):
                return mid
            elif(target > nums[mid]):
                l = mid + 1
            else:
                r = mid - 1
        return l
