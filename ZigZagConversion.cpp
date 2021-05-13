/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
 
Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
class Solution {
public:
    string convert(string s, int numRows) {
        //To be honest this seems pretty easy. Let's check. 
        
        // If the number of rows is 1, we just retur it as it is.
        if(numRows == 1) {
            return s;
        }
        
        //Let's keep an array of strings, one for each row. 
        vector<string> rows(min(numRows, int(s.size())));
        int current = 0;
        bool goingDown = false;
        int temp;
        
        for (char c : s) {
            rows[current] += c;
            if(current == 0 || current == (numRows-1)) {
                goingDown = !goingDown;
            }
            
            if(goingDown == true) {
                current++;
            }
            else {
                current--;
            }
        }
        
        // Now we have filled all the rows, we just have to print it. 
        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};
