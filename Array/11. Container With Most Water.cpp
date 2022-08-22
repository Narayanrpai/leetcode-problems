class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxArea = INT_MIN, area = 0;
        
        while(left < right){
            area = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, area);
            
            if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxArea;
    }
};

