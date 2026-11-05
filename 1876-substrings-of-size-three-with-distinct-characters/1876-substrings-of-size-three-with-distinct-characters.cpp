class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        
        if (s.length() < 3) {
            return 0;
        }
        
        for (int i = 2; i < s.length(); i++) {
            char a = s[i];
            char b = s[i - 1];
            char c = s[i - 2];
            
            if (a != b && a != c && b != c) {
                count = count + 1;
            }
        }
        
        return count;
    }
};
