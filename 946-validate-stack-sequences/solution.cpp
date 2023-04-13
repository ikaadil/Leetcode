class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       int j = 0;
       stack<int>st;
       for(int i = 0 ; i < pushed.size(); i++) {
           st.push(pushed[i]);
           while(!st.empty() and j < popped.size() and st.top() == popped[j]) {
                st.pop();
                j++;
            }   
       }
       return st.empty();
    }
};

/*
TC: O(n)
SC: O(n)
*/