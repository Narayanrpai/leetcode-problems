class Solution {
public:
    int cache[30005][3];
    int solve(vector<int>& prices, int i, bool state){
        if(i == prices.size()){
            return 0;
        }
        if(cache[i][state] != -1){
            return cache[i][state];
        }
        if(state){
            return cache[i][state] = max(-prices[i] + solve(prices, i + 1, 0), solve(prices, i + 1, 1));
        }
        return cache[i][state] = max(prices[i] + solve(prices, i + 1, 1), solve(prices, i + 1, 0));
    }
    
    int maxProfit(vector<int>& prices) {
        
        int N = prices.size();
        cache[N+1][2];
        
        memset(cache, -1, sizeof(cache));
        
        return solve(prices, 0, 1);
    }
};