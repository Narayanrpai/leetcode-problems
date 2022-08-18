class FreqStack {
public:
    unordered_map<int, int> map;
    unordered_map<int, stack<int>> s;
    int maxFreq;
    
    FreqStack() {
        maxFreq = 0;
        map = unordered_map<int, int>();
        s = unordered_map<int, stack<int>>();
    }
    
    void push(int val) {
        map[val]++;
        if(map[val] > maxFreq){
            maxFreq = map[val];
        }
        s[map[val]].push(val);
    }
    
    int pop() {
        int ans = s[maxFreq].top();
        s[maxFreq].pop();
        map[ans]--;
        if(!s[maxFreq].size()){
            maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */