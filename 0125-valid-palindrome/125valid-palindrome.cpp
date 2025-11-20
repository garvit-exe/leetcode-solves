class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size()-1;
        string str = "";
        for (char c : s) {
            if (isalnum(c)) str.push_back(tolower(c));
        }
        string str2 = str;
        reverse(str.begin(), str.end());

        if (str == str2) return true;

        return false;
    }
};