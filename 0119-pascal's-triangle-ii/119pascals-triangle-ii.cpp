class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> pt;
        pt.push_back({1});

        for (int i = 1; i < rowIndex + 1; i++) {
            vector<int> pr = pt[i-1];
            vector<int> cr(i+1,1);

            for (int j = 1; j < i; j++) {
                cr[j] = pr[j-1] + pr[j];
            }

            pt.push_back(cr);
        }

        return pt[pt.size()-1];
    }
};