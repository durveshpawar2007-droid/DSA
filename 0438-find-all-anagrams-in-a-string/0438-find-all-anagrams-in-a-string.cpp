class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<int> result;
        
        if (np > ns) return result;
        
        vector<int> p_counts(26, 0);
        vector<int> window_counts(26, 0);
        
        for (int i = 0; i < np; i++) {
            p_counts[p[i] - 'a']++;
            window_counts[s[i] - 'a']++;
        }
        
        if (p_counts == window_counts) {
            result.push_back(0);
        }
        
        for (int i = np; i < ns; i++) {
            window_counts[s[i] - 'a']++;
            window_counts[s[i - np] - 'a']--;
            
            if (p_counts == window_counts) {
                result.push_back(i - np + 1);
            }
        }
        
        return result;
    }
};
