class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        bool success = true;
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    success = false;
                    break;
                }
            }
            if (success == false) {
                break;
            }
            else {
                count = i + 1;
            }
        } 
        for (int i = 0; i < count; i++) {
            ans = ans + strs[0][i];
        }
        return ans;
    }
};