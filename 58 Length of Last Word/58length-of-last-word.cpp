class Solution {
public:
    int lengthOfLastWord(string s) {
        // vector<string> str;
        // int j = 0;
        // for (int i = 0; i < s.length() - 1; i++) {
        //     if (s[i] == ' ') {
        //         if (str.size() > j) j++;
        //         else continue;
        //         // if (s[i + 1] == ' ') continue;
        //         // else j++;
        //     }
        //     str[j] = str[j] + s[i];
        // }
        // return str[str.size() - 1].length();

        int ind=0;
        int ans=0;
        while(s.length() > ind) {
            if(s[ind] != ' ')
            {
                ans=0;
                while(ind < s.length() && s[ind] != ' '){
                    ans++;
                    ind++;
                }
            }
            ind++;
        }

        return ans;

    }
};