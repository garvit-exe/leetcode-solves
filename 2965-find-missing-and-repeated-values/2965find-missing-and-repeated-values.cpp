class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> um;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                um[grid[i][j]]++;
            }
        }

        vector<int> v(2, -1);
        for (int i = 1; i <= grid.size() * grid.size(); i++) {
            if (um[i] == 2) {
                v[0] = i;
                break;
            }
        }
        for (int i = 1; i <= grid.size() * grid.size(); i++) {
            if (um[i] == 0) {
                v[1] = i;
                break;
            }
        }

        return v;
    }
};