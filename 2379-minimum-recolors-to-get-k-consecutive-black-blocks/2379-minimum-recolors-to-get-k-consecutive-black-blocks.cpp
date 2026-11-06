class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int white_count = 0;
        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white_count = white_count + 1;
            }
        }
        
        int min_ops = white_count;
        
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                white_count = white_count + 1;
            }
            
            if (blocks[i - k] == 'W') {
                white_count = white_count - 1;
            }
            
            min_ops = min(min_ops, white_count);
        }
        
        return min_ops;
    }
};
