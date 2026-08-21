class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int countK = 0, maxOnes = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {

            if (nums[j] == 0)
                countK++;
                
            while (countK > k) {
                if (nums[i] == 0)
                    countK--;
                i++;
            }

            maxOnes = max(maxOnes, j - i + 1);
        }

        return maxOnes;
    }
};