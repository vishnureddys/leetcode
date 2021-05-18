/*
9. Palindrome Number

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        //First test is to check if number is negative. 
        if (x < 0 || (x % 10 == 0 && x != 0 )) return false;
        
        // Now getting the reverse
        int reverse = 0;
        
        while(x > reverse){
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        
        if ( x == reverse || x == reverse/10) {
            return true;
        }
        return false;
    }
};
