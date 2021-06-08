/*
20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> count;
        for (int i = 0; i < s.size(); i++){
            // If the stack is empty, just add it to the stack. 
            if(count.empty()) count.push(s[i]);
            else{
                if (s[i] == ')' && count.top() == '(') count.pop();
                else if (s[i] == '}' && count.top() == '{') count.pop();
                else if (s[i] == ']' && count.top() == '[') count.pop();
                else count.push(s[i]);
            }
        }
        return count.empty();
    }
};
