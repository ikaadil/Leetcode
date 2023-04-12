class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        vector<string>v;
        for(char ch: path + '/') {
            if(ch == '/') {
                if(cur == "..") {
                    if(v.size() > 0) {
                        v.pop_back();
                    }
                } else if(cur != "" and cur != ".") {
                    v.push_back(cur);
                } 
                cur = "";
            } else {
                cur += ch;
            }
        }
        cur = "";
        if(v.size() == 0) {
            return "/";
        }
        for(string s: v) {
            cur += "/" + s;
        }
        return cur;
    }
};

/*
TC: O(n)
SC: O(n)
*/