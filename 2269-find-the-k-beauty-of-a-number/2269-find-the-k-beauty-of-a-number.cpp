class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int k_beauty = 0;
        
        for (int i = 0; i <= n - k; i++) {
            string chunk = s.substr(i, k);
            int value = stoi(chunk);
            
            if (value != 0 && num % value == 0) {
                k_beauty = k_beauty + 1;
            }
        }
        
        return k_beauty;
    }
};
