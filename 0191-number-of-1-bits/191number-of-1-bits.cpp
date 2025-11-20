class Solution {
public:
    int hammingWeight(int n) {
        bitset<64> b(n);
        string s = b.to_string();
        int cnt = 0;

        for (char c : s) {
            if (c == '1') cnt++;
        }

        return cnt;
    }
};