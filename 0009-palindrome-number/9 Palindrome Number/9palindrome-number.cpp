class Solution {
public:
    bool isPalindrome(int x) {
        bool pal = false;
        long a = 0;
        if (x >= 0) {
            int x2 = x;
            while (x2 > 0) {
                a = (a * 10) + (x2 % 10);
                x2 = x2 / 10;
            }
        }
        if (a == x) {
            pal = true;
        }
        return pal;
    }
};