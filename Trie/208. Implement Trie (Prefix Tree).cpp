class Node{
    public:
    
    Node* links[26];
    bool endsHere = 0;
    
    bool exists(char c){
        return links[c - 'a'] != NULL;
    }
    
    Node* getNode(char c){
        return links[c - 'a'];
    }
    
    void createNode(Node* node, char c){
        links[c - 'a'] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node* node = root;
        
        for(int i=0;i<n;i++){
            if(!node->exists(word[i])){
                node->createNode(new Node(), word[i]);
            }
            node = node->getNode(word[i]);
        }
        node->endsHere = 1;
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.length();
        
        for(int i=0;i<n;i++){
            if(!node->exists(word[i])) return false;
            node = node->getNode(word[i]);
        }
        
        return node->endsHere;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* node = root;
        
        for(int i=0;i<n;i++){
            if(!node->exists(prefix[i])) return false;
            node = node->getNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */