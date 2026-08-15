class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0;
        int high = k - 1;

        int windowSum = 0;

        
        for (int i = low; i <= high; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        
        low++;
        high++;

        while (high < n) {
            windowSum += nums[high] - nums[low - 1];

            maxSum = max(maxSum, windowSum);

            low++;
            high++;
        }

        return (double)maxSum / k;
    }
};