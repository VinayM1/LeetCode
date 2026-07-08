class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n), nse(n);

        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // Next Smaller
        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }
};