class Solution {
public:
    int reverseBits(int n) {
        // bitset<32> b(n);
        // string s = b.to_string();
        // reverse(s.begin(), s.end());

        // bitset<32> b2(s);
        // int i = static_cast<int>(b2.to_ulong());

        // return i;

        int res = 0;
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }

        return res;
    }
};