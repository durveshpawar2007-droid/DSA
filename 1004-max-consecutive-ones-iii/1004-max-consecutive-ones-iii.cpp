class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int max_len = 0;
        int max_count = 0; 
        vector<int> counts(2, 0); 
        
        for (int i = 0; i < n; i++) {
            int current_num = nums[i];
            
            counts[current_num] = counts[current_num] + 1;
            
            max_count = max(max_count, counts[1]);
            
            int window_len = i - left + 1;
            int imposters = window_len - max_count;
            
            if (imposters > k) {
                while (imposters > k) {
                    int left_num = nums[left];
                    counts[left_num] = counts[left_num] - 1;
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
