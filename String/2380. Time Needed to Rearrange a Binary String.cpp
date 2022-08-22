class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int n = s.length(), count = 0;
        
        bool exists = 1;
        while(exists){
            exists = 0;
            int i = 0;
            while(i < n){
                if(i + 1 < n)
                if(s[i] == '0' and s[i+1] == '1'){
                    s[i] = '1', s[i+1] = '0';
                    exists = 1;
                    i += 2;
                    continue;
                }
                i++;
            }
            if(exists) count++;
        }

        return count;
    }
};