class Solution {
public:
    
    bool isPalindrome(string& p, int n){
        for (int i = 0, j = n - 1; i < j; i++, j--){
            if (p[i] != p[j]) return false;
        }
        return true;
    }
    
    string breakPalindrome(string p) {
        int n = p.length();
        if(n == 1) return "";
        
        if(p[0] != 'a'){
            p[0] = 'a';
            return p;
        }
        
        int i = 0;
        while (i < n - 1 && p[i] == p[i + 1]) i++;
        
        char temp;
        if (i == n - 1) p[n - 1] = 'b';
        else temp = p[i + 1], p[i + 1] = 'a';
        
        if(!isPalindrome(p, n)) return p;
        
        p[i + 1] = temp;
        p[n - 1] = 'b';
        return p;
    }
};