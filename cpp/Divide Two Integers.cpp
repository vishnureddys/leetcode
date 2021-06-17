/*
29. Divide Two Integers
Medium

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.
*/
class Solution {
public:
    int divide(int A, int B) {
        int ans = 0, sign = A > 0 == B > 0 ? 1 : -1;
        if (B == INT_MIN) return A == B;
        if (A == INT_MIN)
            if (B == 1) return INT_MIN;
            else if (B == -1) return INT_MAX;
            else A += abs(B), ans++;
        A = abs(A), B = abs(B);
        while(A>=B) {
            int i = 0;
            while (A >> i >= B) i++;
            A -= B << i - 1, ans += 1 << i - 1;
        }
        return sign < 0 ? -ans : ans;
    }
};
