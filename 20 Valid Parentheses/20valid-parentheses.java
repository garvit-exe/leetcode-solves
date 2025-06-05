class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        st.push('0');
        st.push(s.charAt(0));

        for (int i = 1; i < s.length(); i++) {
            char x = st.peek();
            st.push(s.charAt(i));
            
            if (x == '(' && st.peek() == ')') {
                st.pop();
                st.pop();
            } else if (x == '{' && st.peek() == '}') {
                st.pop();
                st.pop();
            } else if (x == '[' && st.peek() == ']') {
                st.pop();
                st.pop();
            }
        }

        if (st.size() == 1) {
            return true;
        }

        return false;
    }
}