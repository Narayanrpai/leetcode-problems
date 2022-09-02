class Node{
    public:
    
    //Node* links[26];
    unordered_map<char, Node*> links;
    bool endsHere = 0;
    
    bool exists(char c){
        return links.find(c) != links.end();
    }
    
    void insert(Node* node, char c){
        links[c] = node;
    }
    
    Node* getNode(char c){
        return links[c];
    }
};

class WordDictionary {
private:
    Node* root;
    
public:
    WordDictionary() {
        root = new Node();    
    }
    
    void addWord(string word) {
        int n = word.length();
        Node* node = root;
        
        for(int i=0;i<n;i++){
            if(!node->exists(word[i])){
                node->insert(new Node(), word[i]);
            }
            node = node->getNode(word[i]);
        }
        node->endsHere = 1;
    }
    
    
    bool find(string& word, int n, int idx, Node* x){
        
        Node* node = x;
        
        for(int i = idx; i < n; i++){
            if(word[i] == '.'){
                for(auto& j: node->links){
                    if(find(word, n, i + 1, j.second)) return true;
                }
                return false;
            }
            else{
                if(!node->exists(word[i])) return false;
                node = node->getNode(word[i]);
            }
        }
        return node->endsHere;
    }
    
    bool search(string word) {
        return find(word, word.length(), 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

