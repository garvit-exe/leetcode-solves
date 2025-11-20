class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> um;
        for (int i = 0; i <= s.size()-minSize; i++) {
            unordered_set<char> us;
            for (int k = i; k < i+minSize; k++) {
                us.insert(s[k]);
            }
            if (us.size() <= maxLetters) {
                um[s.substr(i, minSize)]++;
            }
        }
        int mx = 0;
        for (auto &x : um) {
            if (x.second > mx) {
                mx = x.second;
            }
        }

        return mx;
    }
};