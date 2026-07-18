class Solution {
public:
    void moveZeroes(vector<int>& x) {
        int n = x.size();
        int k = 0;
        for(int i=0;i<n;i++){
            if(x[i] != 0){
                swap(x[i],x[k]);
                k++;

            }
        
        }
        
    }
};