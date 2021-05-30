/*
15. 3Sum
Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Sorting the nums array so that we can perform 2 sum on the rest of the array. 
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for (int i = 0; i < (int)nums.size()-2; i++){
            //Checking if the array has a duplicate of if it is a starting index
            if((i == 0) || (i > 0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = nums.size()-1;
                int sum = 0 - nums[i];
                
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> temp = {nums[i], nums[low], nums[high]};
                        result.push_back(temp);
                        while(low < high && nums[low + 1] == nums[low]) low++;
                        while(low < high && nums[high - 1] == nums[high]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] > sum){
                        high--;
                    }
                    else{
                        low++;
                    }
                }
                
            }
        }
        return result;
    }
};
