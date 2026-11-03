class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int max_len = 0;
        int max_count = 0; 
        vector<int> counts(26, 0); 
        
        for (int i = 0; i < n; i++) {
            char current_char = s[i];
            
            counts[current_char - 'A'] = counts[current_char - 'A'] + 1;
            
            max_count = max(max_count, counts[current_char - 'A']);
            
            int window_len = i - left + 1;
            int imposters = window_len - max_count;
            
            if (imposters > k) {
                while (imposters > k) {
                    char left_char = s[left];
                    counts[left_char - 'A'] = counts[left_char - 'A'] - 1;
                    left = left + 1;
                    
                    window_len = i - left + 1;
                    imposters = window_len - max_count;
                }
            }
            
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
