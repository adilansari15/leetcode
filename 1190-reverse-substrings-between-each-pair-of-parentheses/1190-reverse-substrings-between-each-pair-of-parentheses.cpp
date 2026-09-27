class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        vector<int> pairIdx(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();

                pairIdx[i] = j;
                pairIdx[j] = i;
            }
        }

        string ans;
        int i = 0;
        int dir = 1;

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pairIdx[i];
                dir = -dir;
            } else {
                ans += s[i];
            }

            i += dir;
        }

        return ans;
    }
};