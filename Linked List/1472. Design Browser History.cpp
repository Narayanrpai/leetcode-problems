class Node{
public:
    Node* next = NULL;
    Node* prev = NULL;
    string val;
};

class BrowserHistory {
private: Node* head;
    
public:
    BrowserHistory(string homepage) {
        head = new Node();
        head->val = homepage;
    }
    
    void visit(string url) {
        Node* temp = new Node();
        temp->val = url;
        temp->prev = head;
        head->next = temp;
        head = temp;
    }
    
    string back(int steps) {
        
        int count = 0;
        while(head != NULL && head->prev != NULL && count != steps){
            head = head->prev;
            count++;
        }
        return head->val;
    }
    
    string forward(int steps) {
        
        int count = 0;
        while(head != NULL && head->next != NULL && count != steps){
            head = head->next;
            count++;
        }
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
