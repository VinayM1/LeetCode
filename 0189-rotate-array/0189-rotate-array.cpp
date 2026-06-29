class Solution {
public:
    void rotate(vector<int>& x, int k) {
        int n = x.size();
        k = k%n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[(i+k)%n] = x[i];
            
    }
    x = arr;
        
    }
};