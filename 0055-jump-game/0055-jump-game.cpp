class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        for(int i = 0; i<n;i++){
            if(i>maxsum){
                return false;
            }
            maxsum = max(maxsum,i+nums[i]);
            if(maxsum>=n-1){
                return true;
            }
        }
        return true;
    }
};