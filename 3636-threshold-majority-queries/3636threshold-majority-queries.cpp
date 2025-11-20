class Solution {
public:
    // Global block_size for the comparator
    int block_size;

    // Structure to hold query information, including its original index
    struct Query {
        int l, r, threshold, id;
    };

    // Custom comparator for sorting queries based on Mo's algorithm
    struct CompareQueries {
        int block_size;
        CompareQueries(int size) : block_size(size) {}
        bool operator()(const Query& a, const Query& b) const {
            int block_a = a.l / block_size;
            int block_b = b.l / block_size;
            if (block_a != block_b) {
                return block_a < block_b;
            }
            // Mo's algorithm optimization: zig-zag pattern for the right pointer
            return (block_a % 2) ? (a.r < b.r) : (a.r > b.r);
        }
    };

    // Data for the current window [current_l, current_r]
    vector<int> freq;
    map<int, set<int>> freq_to_nums;

    // Function to add an element to our window
    void add(int val) {
        if (freq[val] > 0) {
            freq_to_nums[freq[val]].erase(val);
            if (freq_to_nums[freq[val]].empty()) {
                freq_to_nums.erase(freq[val]);
            }
        }
        freq[val]++;
        freq_to_nums[freq[val]].insert(val);
    }

    // Function to remove an element from our window
    void remove(int val) {
        freq_to_nums[freq[val]].erase(val);
        if (freq_to_nums[freq[val]].empty()) {
            freq_to_nums.erase(freq[val]);
        }
        freq[val]--;
        if (freq[val] > 0) {
            freq_to_nums[freq[val]].insert(val);
        }
    }

    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& raw_queries) {
        int n = nums.size();
        int q_count = raw_queries.size();
        block_size = static_cast<int>(sqrt(n));

        // Coordinate Compression
        vector<int> unique_vals = nums;
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());

        unordered_map<int, int> val_to_compressed;
        vector<int> compressed_to_val(unique_vals.size());
        for (size_t i = 0; i < unique_vals.size(); ++i) {
            val_to_compressed[unique_vals[i]] = i;
            compressed_to_val[i] = unique_vals[i];
        }

        vector<int> compressed_nums(n);
        for (int i = 0; i < n; ++i) {
            compressed_nums[i] = val_to_compressed[nums[i]];
        }

        // *** FIX: Create a vector of Query structs from the raw input ***
        vector<Query> queries(q_count);
        for(int i = 0; i < q_count; ++i) {
            queries[i] = {raw_queries[i][0], raw_queries[i][1], raw_queries[i][2], i};
        }

        // Sort the structured queries
        sort(queries.begin(), queries.end(), CompareQueries(block_size));

        vector<int> ans(q_count);
        freq.assign(unique_vals.size(), 0);
        freq_to_nums.clear();

        int current_l = 0, current_r = -1;

        // Process sorted queries
        for (const auto& q : queries) {
            // Move window [current_l, current_r] to [q.l, q.r]
            while (current_l > q.l) {
                current_l--;
                add(compressed_nums[current_l]);
            }
            while (current_r < q.r) {
                current_r++;
                add(compressed_nums[current_r]);
            }
            while (current_l < q.l) {
                remove(compressed_nums[current_l]);
                current_l++;
            }
            while (current_r > q.r) {
                remove(compressed_nums[current_r]);
                current_r--;
            }

            // Answer the query
            // The conceptual subarray `jurnavalic` is now represented by our data structures.
            auto it = freq_to_nums.rbegin();
            int result_element = -1;

            if (it != freq_to_nums.rend() && it->first >= q.threshold) {
                int compressed_result = *(it->second.begin());
                result_element = compressed_to_val[compressed_result];
            }
            // *** FIX: Store the answer in the correct original position ***
            ans[q.id] = result_element;
        }

        return ans;
    }
};