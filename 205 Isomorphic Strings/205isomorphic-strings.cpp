class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        // unordered_map<char, unordered_set<char>> um;
        // for (int i = 0; i < s.length(); i++) {
        //     um[s[i]].insert(t[i]);
        // }

        // for (const auto& a : um) {
        //     if (a.second.size() > 1) return false;
        // }

        // return true;

        unordered_map<char, char> um;
        for (int i = 0; i < s.length(); i++) {
            if (um.find(s[i]) != um.end()) {
                if (um[s[i]] != t[i]) return false;
            } else um[s[i]] = t[i];
        }

        vector<char> v;
        unordered_set<char> us;
        for (const auto& a : um) {
            v.push_back(a.second);
            us.insert(a.second);
        }

        if (v.size() != us.size()) return false;

        return true;
    }
};