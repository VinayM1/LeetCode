class Solution {
public:
    void rotate(vector<vector<int>>& x) {
        int n = x.size();
        //Transpose
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(x[i][j],x[j][i]);
            }
        }
        //reverse
        for(int i = 0;i<n;i++){
            reverse(x[i].begin(),x[i].end());
        }
        
    }
   // reverse + transpose = rotated image 
};