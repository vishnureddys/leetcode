/*
28. Implement strStr()
Easy

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        if(haystack.size() == 0 || haystack.size() < needle.size()) {
            return -1;
        }
        
        // Now we run 2 nested loops
        for(int i = 0; i < haystack.size(); i++) {
            if(i + needle.size() > haystack.size()) return -1;
            
            // Now we compare from every position. 
            for(int j = 0; j < needle.size(); j++) {
                if(haystack[i+j] != needle[j]) {
                    break;
                }
                if(j == needle.size() - 1) return i;
            }
        }
        
        return -1;
        
    }
};
