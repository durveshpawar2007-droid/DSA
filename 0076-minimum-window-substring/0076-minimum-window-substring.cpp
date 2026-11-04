class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        vector<int> req_counts(256, 0);
        for (char c : t) {
            req_counts[c]++;
        }
        
        int unique_targets = 0;
        for (int i = 0; i < 256; i++) {
            if (req_counts[i] > 0) {
                unique_targets++;
            }
        }
        
        vector<int> window_counts(256, 0);
        int left = 0;
        int formed = 0;
        
        int min_len = INT_MAX;
        int start_idx = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char current_char = s[i];
            
            window_counts[current_char]++;
            
            if (req_counts[current_char] > 0 && window_counts[current_char] == req_counts[current_char]) {
                formed++;
            }
            
            while (formed == unique_targets) {
                int current_window_len = i - left + 1;
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }
                
                char left_char = s[left];
                
                if (req_counts[left_char] > 0 && window_counts[left_char] == req_counts[left_char]) {
                    formed--;
                }
                
                window_counts[left_char]--;
                left = left + 1;
            }
        }
        
        if (min_len == INT_MAX) return "";
        return s.substr(start_idx, min_len);
    }
};
