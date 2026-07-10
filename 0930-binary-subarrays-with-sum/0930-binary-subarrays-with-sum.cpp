class Solution {
public:

    int atMost(vector<int>& nums, int goal){

        if(goal < 0)
            return 0;

        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;

        while(r < nums.size()){

            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);

            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};