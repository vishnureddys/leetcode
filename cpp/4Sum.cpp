/*
18. 4Sum
Medium

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        // If the length of the vector is less than 4
        if(nums.size() < 4) return result;
        
        // Now we sort the vector. 
        sort(nums.begin(),nums.end());
        
        // Now coming to the main algorithm. 
        for(int i = 0; i < nums.size()-3; i++){
            if (i > 0 && nums[i-1] == nums[i]) continue;
            
            for (int j = i + 1; j < nums.size()-2; j++){
                if(j > i + 1 && nums[j-1] == nums[j]) continue;
                
                int sumA = nums[i] + nums[j];
                int low = j + 1;
                int high = nums.size() - 1;
                
                while(low < high){
                    int sumB = sumA + nums[low] + nums[high];
                    if (sumB == target){
                        vector<int> temp = {nums[i], nums[j], nums[low], nums[high]};
                        result.push_back(temp);
                        low++;
                        high--;
                        while(nums[low] == nums[low-1] && low < high) low++;
                        while(nums[high] == nums[high+1] && low < high) high--;
                    }
                    else if (sumB > target){
                        high --;
                    }
                    else{
                        low ++;
                    }
                }
            }
        }
        return result;
    }
};
