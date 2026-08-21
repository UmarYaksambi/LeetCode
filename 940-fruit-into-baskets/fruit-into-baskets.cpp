class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        unordered_set<int> weHave;

        int maxFruits = 0, basketUsed = 0;

        for(int i = 0, j = 0; j < fruits.size(); j++) {
            if(weHave.find(fruits[j]) == weHave.end()) {
                basketUsed++;
                weHave.insert(fruits[j]);

            }
            
            freq[fruits[j]]++;

            while(basketUsed > 2) {
                int lastFruit = fruits[i];
                freq[lastFruit]--;
                i++;

                if(freq[lastFruit] == 0) {
                    basketUsed--;
                    weHave.erase(lastFruit);
                }
            }

            maxFruits = max(maxFruits, j - i + 1);
        }

        return maxFruits;
    }
};