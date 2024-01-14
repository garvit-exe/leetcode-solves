class Solution {
public:
    bool isValid(string s) {
        bool valid = false;
        stack<char> brackets;
        brackets.push('a');
        brackets.push(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (brackets.size() != 0) {
                char x = brackets.top();
                brackets.push(s[i]);
                if (x == '(' && brackets.top() == ')') {
                    brackets.pop();
                    brackets.pop();
                } else if (x == '{' && brackets.top() == '}') {
                    brackets.pop();
                    brackets.pop();
                } else if (x == '[' && brackets.top() == ']') {
                    brackets.pop();
                    brackets.pop();
                }
            }
        }
        if (brackets.size() == 1) {
            valid = true;
        }
        return valid;
    }
};