class Node{
    public:
    
    Node* links[26];
    bool endsHere = 0;
    
    bool exists(char c){
        return links[c - 'a'] != NULL;
    }
    
    void insert(Node* node, char c){
        links[c - 'a'] = node;
    }
    
    Node* getNode(char c){
        return links[c - 'a'];
    }
};

class MagicDictionary {
private: Node* root;
    
public:
    MagicDictionary() {
        root = new Node();        
    }
    
    void buildDict(vector<string> dictionary) {
        
        for(auto& word: dictionary){
            Node* node = root;
            for(auto& i: word){
                if(!node->exists(i)){
                    node->insert(new Node(), i);
                }
                node = node->getNode(i);
            }
            node->endsHere = 1;
        }
    }
    
    bool found(string& s, int n){
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->exists(s[i])) return false;
            node = node->getNode(s[i]);
        }
        
        return node->endsHere;
    }
    
    bool search(string s) {
        int n = s.length();
        
        for(int i=0;i<n;i++){
            char temp = s[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(ch == s[i]) continue;
                
                s[i] = ch;
                //cout << s << ' ';
                if(found(s, n)) return true;   
                s[i] = temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
