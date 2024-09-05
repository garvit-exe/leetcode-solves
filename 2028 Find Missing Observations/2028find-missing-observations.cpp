class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        int total = (n + m) * mean;
        int err = total - sum;

        if ((err > 6 * n) || (err < n)) return {};

        auto [q, r] = div(err, n);
        vector<int> ans(n, q);
        fill(ans.begin(), ans.begin() + r, q + 1);

        return ans;
    }
};