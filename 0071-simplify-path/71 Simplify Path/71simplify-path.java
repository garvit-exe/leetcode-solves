class Solution {
    public String simplifyPath(String path) {
        String[] dir = path.split("/");
        Stack<String> st = new Stack<String>();

        for (String s : dir) {
            if (s.equals("") || s.equals(".")) {
                continue;
            }

            if (s.equals("..")) {
                if (!st.isEmpty()) {
                    st.pop();
                }
            } else {
                st.push(s);
            }
        }

        StringBuilder str = new StringBuilder();
        while (!st.isEmpty()) {
            str.insert(0, "/" + st.peek());
            st.pop();
        }

        return (str.length() == 0) ? "/" : str.toString();
    }
}