/*
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    // Helper function added by me
    string findPrefix(string s1, string s2) {
        int n = min(s1.size(), s2.size());
        string result = "";
        for (int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                break;
            }
            result.push_back(s1[i]);
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            result = findPrefix(result, strs[i]);
        }
        return result;
    }
};
