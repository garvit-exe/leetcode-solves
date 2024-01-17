class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        unordered_set<int> us;
        for (int num: arr) {
            um[num]++;
        }
        for (const auto& entry: um) {
            if (us.find(entry.second) != us.end()) {
                return false;
            }
            us.insert(entry.second);
        }
        return true;
    }
};