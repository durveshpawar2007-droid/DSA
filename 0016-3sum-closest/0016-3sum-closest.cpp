class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        int max_diff = INT_MAX; 
        int result_Sum = 0;
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int Sum = nums[i] + nums[left] + nums[right];
                
                if (Sum == target) {
                    return Sum;
                }
                
                int diff = std::abs(Sum - target);
                
                if (diff < max_diff) {
                    max_diff = diff;
                    result_Sum = Sum;
                }
                
                if (Sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result_Sum;
        
    }
};