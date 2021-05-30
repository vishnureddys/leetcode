/*
Link to problem - https://helloml.org/reverse-integer-handling-overflow-solution-to-leetcode-problem/
*/
import java.util.*;
class Solution {
    public static int reverse(int x) {
        if (x == Integer.MIN_VALUE)
            return 0;
        int y = 1, result = 0, n = 0;
        if (x < 0)
            y = -1;
        x = Math.abs(x);
        while (x != 0 && n < 9) {
            int remainder = x % 10;
            result = 10 * result + remainder;
            x = x / 10;
            n++;
        }
        if (result > Integer.MAX_VALUE / 10 && x > 0)
            return 0;
        else if (x > 0) {
            result = result * 10 + x;
        }
        return y * result;
    }
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        System.out.println(reverse(x));
    }
}
