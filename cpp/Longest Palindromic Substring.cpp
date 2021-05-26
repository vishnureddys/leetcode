/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        
        // Creating a table to store previous substring's isPalindrome Condition. 
        bool table[n][n];
        memset(table, 0, sizeof(table));
        
        // Setting it to 1 for all substring of size 1 because they are palindromes. 
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        maxLength = 1; // All substrings of size 1 are palindromes. 
        int start = 0;
        // Checking for all substrings of length 2. 
        for (int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]){
                start = i;
                table[i][i+1] = true;
                maxLength = 2;
            }
        }
        
        // Now we handle cases of length greater than 2 i.e. from 3 to n.  
        // k is to handle the length of each substring. 
        for (int k = 3; k <= n; k++) {
            // Now we traverse each substring of size k
            for (int i = 0; i < n-k+1; i++) {
                // End index of substring
                int j = i + k - 1;
                
                // Now make use of DP
                if (table[i+1][j-1] && s[i]==s[j]) {
                    table[i][j] = true;
                    
                    if(k > maxLength) {
                        maxLength = k;
                        start = i;
                    }
                }
            }
        }
        cout<< maxLength;
        // Now printing the output
        return s.substr(start, maxLength);
    }
};
