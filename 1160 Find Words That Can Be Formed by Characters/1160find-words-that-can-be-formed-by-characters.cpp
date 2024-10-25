class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> cnt;
        
        for (char c: chars) {
            cnt[c]++;
        }
        
        int ans = 0;
        
        for (string w: words) {
            unordered_map<char, int> cnt2;
            
            for (char c: w) {
                cnt2[c]++;
            }
            
            bool possible = true;
            
            for(char c: w) {
                if(cnt[c]<cnt2[c])
                    possible = false;
            }
            
            if(possible) ans+=w.size();
        }
        
        return ans;
    }
};