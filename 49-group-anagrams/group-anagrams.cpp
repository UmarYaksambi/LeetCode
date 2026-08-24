class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umm;

        for(auto word : strs) {

            string cur = word;
            sort(cur.begin(), cur.end());

            umm[cur].push_back(word);
        }

        for(auto ana : umm) {
            ans.push_back(ana.second);
        }

        return ans;
    }
};