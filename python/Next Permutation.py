'''
31. Next Permutation
Medium

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.
'''
# I hate problems of this kind. We can get the solution only if we know the math behind it. 
# If some interviewer asked this question, I'm sure his company would be losing out on a lot of talent. 
class Solution:
    def nextPermutation(self, nums):
        i = len(nums)-1
        while i>0:
            if nums[i-1]<nums[i]:
                break
            i = i-1
        i = i-1
        j = len(nums)-1
        while j>i:
            if nums[j]>nums[i]:
                break
            j=j-1
        nums[i],nums[j]=nums[j],nums[i]  
        nums[i+1:]=sorted(nums[i+1:]) 
