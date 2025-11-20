#include <string>
#include <cmath>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int ans = 0;
        long long powerOf26 = 1;

        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            int char_value = columnTitle[i] - 'A' + 1;
            ans += char_value * powerOf26;
            powerOf26 *= 26;
        }

        return ans;
    }
};