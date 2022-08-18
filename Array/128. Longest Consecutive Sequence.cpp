class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            set.insert(nums[i]);
        }
        nums.clear();
        for(auto& i: set){
            nums.push_back(i);
        }
        priority_queue<int> pq(nums.begin(), nums.end());
        
        int res = 1;
        int count = 1;
        
        int prev = pq.top();
        pq.pop();
        
        while(!pq.empty()){
            if(pq.top() + 1 == prev){
                prev = pq.top();
                pq.pop();
                count++;
                res = max(res, count);
            }
            else{
                count = 1;
                prev = pq.top();
                pq.pop();
            }
        }
        return res;
    }
};