class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;              
        int max_len = 0;        
        unordered_map<char, int> last_seen; 
        
        for (int i = 0; i < n; i++) {
            char current_char = s[i];

            if (last_seen.count(current_char) && last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }
            
            last_seen[current_char] = i;
            
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
