class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch: s) {
            if(ch == '(' or ch == '{' or ch == '[') {
                st.push(ch);
            } else {
                if(ch == ')' and !st.empty() and st.top() == '(') {
                    st.pop();
                } else if(ch == '}' and !st.empty() and st.top() == '{') {
                    st.pop();
                } else if(ch == ']' and !st.empty() and st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};

/*
TC: O(n)
SC: O(n)
*/