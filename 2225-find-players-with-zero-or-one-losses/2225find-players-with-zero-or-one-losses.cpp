class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer = {{}, {}};
        unordered_map<int, int> losses;
        unordered_map<int, int> wins;
        for (vector<int> match: matches) {
            losses[match[1]]++;
        }
        for (vector<int> match: matches) {
            wins[match[0]]++;
        }
        for (const auto& entry: wins) {
            if (losses.find(entry.first) == losses.end()) {
                answer[0].push_back(entry.first);
            }
        }
        for (const auto& entry: losses) {
            if (entry.second == 1) {
                answer[1].push_back(entry.first);
            }
        }
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        // answer[1].erase(unique(answer[1].begin(), answer[1].end()), answer[1].end());
        return answer;
    }
};