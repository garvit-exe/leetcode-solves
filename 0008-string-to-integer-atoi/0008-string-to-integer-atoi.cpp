class Solution {
public:
    int myAtoi(string s) {
        string str = "";
        bool fnd = false;
        for (char c : s) {
            if (!fnd && c == ' ') continue;
            else if (!fnd && (c == '-' || c == '+')) {
                str += c;
                fnd = true;
            } else if (!isdigit(c)) {
                break;
            } else {
                str += c;
                fnd = true;
            }
        }
        if (str == "" || str == "-" || str == "+") return 0;

        try {
            int i = stoi(str);
            return i;
        } catch (std::out_of_range& e) {
            if (str[0] == '-') return -1 * pow(2, 31);
            return pow(2, 31) - 1;
        }
    }
};