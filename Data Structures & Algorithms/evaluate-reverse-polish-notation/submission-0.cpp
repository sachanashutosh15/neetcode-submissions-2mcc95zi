class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+", "-", "*", "/"};
        stack<int> st;
        for (string token: tokens) {
            if (!operators.count(token)) {
                st.push(stoi(token));
                continue;
            }
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(b - a);
            } else if (token == "*") {
                st.push(b * a);
            } else if (token == "/") {
                st.push(b / a);
            }
        }
        return st.top();
    }
};
