class Solution {
public:
    int mySqrt(int x) {
        int mid;
        int i = 1;
        int a = x;
        if (x == 0 || x == 1) {
            return x;
        }
        while (i <= a) {
            mid = i + ((a - i) / 2);
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                i = mid + 1;
            } else {
                a = mid - 1;
            }
        }
        return a;
    }
};