class WordDictionary {
public:
    struct TreeNode {
        TreeNode* children[26] = {nullptr};
        bool endOfWord = false;
    };

    TreeNode* root;

    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node -> children[word[i] - 'a'] == nullptr) {
                node -> children[word[i] - 'a'] = new TreeNode();
            }
            node = node -> children[word[i] - 'a'];
        }
        node -> endOfWord = true;
    }

    bool _search(TreeNode* node, string word, int index) {
        if(index == word.size() and node -> endOfWord) {
            return true;
        }
        for(int i = index; i < word.size(); i++) {
            if(word[i] == '.') {
                bool result = false;
                for(int j = 'a'; j <= 'z'; j++) {
                    if(node -> children[j - 'a']) {
                        result = result or _search(node -> children[j - 'a'], word, i + 1);
                    }
                }
                return result;
            } else {
                if(node -> children[word[i] - 'a'] == nullptr) {
                    return false;
                }
                node = node -> children[word[i] - 'a'];
            }
        }
       return node -> endOfWord; 
    }
    
    bool search(string word) {
        return _search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


 /** 
 TC:
    add -> O(n)
    search -> 26 * 26 * 26 * n
              O(n)

 SC: 
    add -> O(n)
    search -> O(1)

*/