class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int index = 0, num;
        
        while(true){
            num = nums[index];
            if(num == -1){
                return index;
            }
            nums[index] = -1;
            index = num;
        }
        return -1;
    }
};

