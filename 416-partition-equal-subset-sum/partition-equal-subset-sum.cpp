class Solution {
private:
    bool dp(int i, int target, vector<int>& nums, vector<vector<int>>& memo) {
        if(target == 0) return true;

        if(i == 0) return target == nums[0];

        if(memo[i][target] != -1) return memo[i][target];

        bool notPick = dp(i - 1, target, nums, memo);
        bool pick = false;
        if(nums[i] <= target)
            pick = dp(i - 1, target - nums[i], nums, memo);

        return memo[i][target] = pick || notPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));


        return dp(nums.size() - 1, target, nums, memo);
    }
};