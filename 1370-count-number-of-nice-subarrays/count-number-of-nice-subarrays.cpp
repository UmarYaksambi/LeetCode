class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int valid = 0, currentK = 0;

        for(int i = 0, j = 0; j < nums.size(); j++) {
            if(nums[j] % 2 != 0)
                currentK++;

            while(currentK > k) {
                if(nums[i] % 2 != 0)
                    currentK--;
                i++;
            }

            valid += j - i + 1;
        }

        return valid;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);    
    }
};