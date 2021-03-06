/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<char, string> map = 
        {
            {'2',"abc"}, 
            {'3', "def"}, 
            {'4', "ghi"}, 
            {'5', "jkl"}, 
            {'6', "mno"}, 
            {'7', "pqrs"}, 
            {'8', "tuv"}, 
            {'9',"wxyz"}
        };
        vector<string> ans;
        
        // For all the letters in the number
        for(int i=0;i<n;i++){
            string letters = map[digits[i]];
            // If the ans vector is empty
            if(ans.empty()) {
                // Get all the characters and put it into the ans vector
                for(int j=0;j<letters.size();j++){
                    string s; s += letters[j];
                    ans.push_back(s);
                }
            }
            // If ans already has some element
            else {
                // new_ans would have (n*m) elements.
                vector<string> new_ans;
                for(int j=0;j<letters.size();j++)
                    for(int k=0;k<ans.size(); k++)
                        new_ans.push_back(ans[k]+letters[j]);
                ans = new_ans;
            }
        }
        return ans;
    }
};
