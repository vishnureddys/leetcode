/*
10. Regular Expression Matching
Hard

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false

Constraints:
0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // If the pattern is empty, then the string has to be empty. 
        if(p.empty()) return s.empty();
        
        // Now checking for first match. 
        bool first_match = !s.empty() && (s[0] == p[0] || '.' == p[0]);
        
        if(p.size() >= 2 && p[1] == '*' ){
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1),p));
        }
        else{
            return first_match && isMatch(s.substr(1),p.substr(1));
        }
    }
};
