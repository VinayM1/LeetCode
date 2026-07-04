class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> pse(n), nse(n), pge(n), nge(n);

        stack<int> st;

        // Previous Smaller
        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        // Next Smaller
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Previous Greater
        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        // Next Greater
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for(int i = 0; i < n; i++){

            long long left = i - pse[i];
            long long right = nse[i] - i;

            minSum += 1LL * nums[i] * left * right;

            left = i - pge[i];
            right = nge[i] - i;

            maxSum += 1LL * nums[i] * left * right;
        }

        return maxSum - minSum;
    }
};