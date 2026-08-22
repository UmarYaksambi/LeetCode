class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int index, vector<int> current) {
        if(index == nums.size()) {
            result.push_back(current);
            return;

        }


        current.push_back(nums[index]);
        backtrack(nums, index + 1, current);

        current.pop_back();
        backtrack(nums, index + 1, current);
    }
    

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0, {});

        return result;
    }
};