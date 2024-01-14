class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequency_map;

        for(int num : nums) {
            frequency_map[num]++;
        }

        int max_frequency = 0;
        for(const auto& entry : frequency_map) {
            max_frequency = max(max_frequency, entry.second);
        }

        int total_frequencies = 0;
        for(const auto& entry : frequency_map) {
            if(entry.second == max_frequency) {
                total_frequencies += entry.second;
            }
        }

        return total_frequencies;
    }
};