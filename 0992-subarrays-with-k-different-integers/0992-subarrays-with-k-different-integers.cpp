class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> counts(n + 1, 0);
        int left = 0;
        int distinct = 0;
        int total_subarrays = 0;
        
        for (int right = 0; right < n; right++) {
            int current_num = nums[right];
            if (counts[current_num] == 0) {
                distinct = distinct + 1;
            }
            counts[current_num] = counts[current_num] + 1;
            
            while (distinct > k) {
                int left_num = nums[left];
                counts[left_num] = counts[left_num] - 1;
                if (counts[left_num] == 0) {
                    distinct = distinct - 1;
                }
                left = left + 1;
            }
            
            total_subarrays = total_subarrays + (right - left + 1);
        }
        
        return total_subarrays;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
