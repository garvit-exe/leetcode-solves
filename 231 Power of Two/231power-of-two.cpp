class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double d = log2((double)n);
        if (d == (int)d) return true;

        return false;
    }
};