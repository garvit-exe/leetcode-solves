class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;

        for (char c: s) {
            int x = c - 'a' + 1;
            auto [q, r] = div(x, 10);
            num += q + r;
        }

        if (k == 1) return num;

        k--;
        for (int i = num; i >= 10 && k > 0; k--) {
            for (num = 0; i > 0;) {
                auto [q, r] = div(i, 10);
                num += r;
                i = q;
            }

            i = num;
        }

        return num;
    }
};