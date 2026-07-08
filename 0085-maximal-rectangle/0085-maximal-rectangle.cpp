class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n), nse(n);

        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);

        int ans = 0;

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(matrix[i][j] == '1')
                    height[j]++;

                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};