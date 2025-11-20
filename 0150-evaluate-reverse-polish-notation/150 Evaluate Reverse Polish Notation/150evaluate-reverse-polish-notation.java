class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<Integer>();
        for (String s : tokens) {
            int total = 0;

            if (!st.isEmpty() && s.equals("+")) {
                total += st.pop();
                total += st.pop();
                st.push(total);
                continue;
            }
            if (!st.isEmpty() && s.equals("-")) {
                total -= st.pop();
                total += st.pop();
                st.push(total);
                continue;
            }
            if (!st.isEmpty() && s.equals("*")) {
                total += st.pop();
                total *= st.pop();
                st.push(total);
                continue;
            }
            if (!st.isEmpty() && s.equals("/")) {
                int temp = st.pop();
                total += st.pop();
                total /= temp;
                st.push(total);
                continue;
            }
            
            st.push(Integer.parseInt(s));
        }

        if (st.size() == 1) return st.peek();

        return -1;
    }
}