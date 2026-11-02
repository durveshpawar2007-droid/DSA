class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int max_fruits = 0;
        unordered_map<int, int> fruit_counts;
        
        for (int i = 0; i < n; i++) {
            fruit_counts[fruits[i]]++;
            
            if (fruit_counts.size() > 2) {
                while (fruit_counts.size() > 2) {
                    fruit_counts[fruits[left]]--;
                    if (fruit_counts[fruits[left]] == 0) {
                        fruit_counts.erase(fruits[left]);
                    }
                    left++;
                }
            }
            
            max_fruits = max(max_fruits, i - left + 1);
        }
        return max_fruits;
    }
};
