'''
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
'''
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # As mentioned earlier, if we see O(log n), we must undertand that we have to use binary search
        l = 0
        r = len(nums) - 1
        while(l <= r):
            mid = int(l+(r-l)/2)
            if(nums[mid] == target):
                # We need to check if the previous elemens are also targets
                i = mid - 1
                while(nums[i] == target and i >= 0):
                    i -= 1
                # Now we have the min value
                j = mid + 1
                while(j < len(nums) and nums[j] == target):
                    j += 1
                return (i+1, j-1)
            elif(nums[mid] < target):
                l = mid + 1
            else:
                r = mid - 1
        return (-1, -1)
