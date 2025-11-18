class Solution {
public:
    bool isDuplicate(string s) {
        unordered_map<char, int> um;
        for (char c : s) {
            um[c]++;
            if (um[c] > 1) return true;
        }

        return false;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        
        int i = 0, j = 0;
        int mx = 1;
        while (j >= i && j < s.size()) {
            string str = s.substr(i, j - i + 1);
            if (isDuplicate(str)) i++;
            else {
                mx = max(mx, j - i + 1);
                j++;
            }
        }

        return mx;
    }
};