class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
        return {};

        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> prev_row = pascalTriangle[i-1];
            vector<int> current_row(i+1,1);
            for (int j = 1; j < i; j++) {
                current_row[j] = prev_row[j-1] + prev_row[j];
            }
            pascalTriangle.push_back(current_row);
        }

        return pascalTriangle;
    }
};