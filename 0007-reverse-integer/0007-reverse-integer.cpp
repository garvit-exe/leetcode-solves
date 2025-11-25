class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s[0] == '-') std::reverse(s.begin() + 1, s.end());
        else std::reverse(s.begin(), s.end());

        long long ll = stoll(s);
        if (ll < -1 * pow(2, 31) || ll > pow(2, 31) - 1) return 0;
        return ll;
    }
};