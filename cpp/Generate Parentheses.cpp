/*
22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:

    1 <= n <= 8
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, 0, 0,"", n);
        return output;
    }
    
    void backtrack(vector<string> &output, int open, int close, string current, int n){
        if(current.size() == n * 2){
            output.push_back(current);
            return;
        }
        if (open < n){
            backtrack(output, open+1, close, current + "(", n);
        }
        if (close < open){
            backtrack(output, open, close + 1, current + ")", n);
        }
    }
    
};
