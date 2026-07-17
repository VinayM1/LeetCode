class Solution {
public:
    int singleNumber(vector<int>& x) {
        int n = x.size();
        int k = 0;
        for(int i=0;i<n;i++){

            k = k ^ x[i];

            
        }
        return k;
            
           

            
        
    }
};