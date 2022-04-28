class Trie {
public:
    vector<Trie*> next;
    bool isEnd;

    Trie() :next(26, nullptr), isEnd(false){

    }
    
    void insert(string word) {
        Trie *node = this;
        for(char c : word)
        {
            int index = c - 'a';
            if(node->next[index] == nullptr)
            {
                node->next[index] = new Trie();
            }
            node = node->next[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for(auto c : word)
        {
            int index = c-'a';
            if(node->next[index] == nullptr)
                return false;
            else
            {
                node = node->next[index];
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for(auto c : prefix)
        {
            int index = c - 'a';
            if(node->next[index] == nullptr)
                return false;
            else
                node = node->next[index];
        }
        return node!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
