class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windowSize = cardPoints.size() - k;
        int windowPoints = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minPoints = windowPoints;

        for(int i = 1, j = windowSize; j < cardPoints.size(); j++, i++) {
            windowPoints = windowPoints + cardPoints[j] - cardPoints[i-1];
            minPoints = min(minPoints, windowPoints);
        }

        return totalPoints - minPoints;
    }
};