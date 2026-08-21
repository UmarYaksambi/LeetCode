class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        unordered_set<char> seen;

        int maxSize = 1;

        for(int i = 0, j = 0; j < s.size(); j++) {
            while(seen.find(s[j]) != seen.end()) {
                seen.erase(s[i]);
                i++;
            }

            seen.insert(s[j]);
            maxSize = max(maxSize, j - i + 1);
        }

        return maxSize;  
    }
};