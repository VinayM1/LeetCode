class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;

        // Take first k cards from the left
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        maxSum = leftSum;

        int rightIndex = n - 1;

        // Remove one card from left and add one from right
        for(int i = k - 1; i >= 0; i--){

            leftSum -= cardPoints[i];

            rightSum += cardPoints[rightIndex];

            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};