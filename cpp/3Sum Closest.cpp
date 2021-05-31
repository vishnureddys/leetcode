/*
16. 3Sum Closest
Medium

Share
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:
Input: nums = [-1,2,1,-4], target = 1

Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //First we sort the array
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        //Now we take one by one for i
        for(int i = 0; i < nums.size()-2; i++){
            int req = target - nums[i];
            if(i == 0 || (i>0 && nums[i-1]!=nums[i])){
                int low = i+1;
                int high = nums.size()-1;
                
                while(low < high){
                    int sum = nums[low] + nums[high];
                    if(abs(req-sum) < abs(diff)){
                        diff = req - sum;
                    }
                    if(sum < req){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return target - diff;
    }
};
