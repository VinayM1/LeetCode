class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& x) {
        int n = x.size();
        int m = x[0].size();

        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;

        vector<int> ans;

        while(top <= bottom && left <= right){

            // 1️⃣ Move left → right
            for(int i = left; i <= right; i++){
                ans.push_back(x[top][i]);
            }
            top++;

            // 2️⃣ Move top → bottom
            for(int i = top; i <= bottom; i++){
                ans.push_back(x[i][right]);
            }
            right--;

            // 3️⃣ Move right → left
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(x[bottom][i]);
                }
                bottom--;
            }

            // 4️⃣ Move bottom → top
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(x[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};