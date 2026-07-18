class Solution {
public:
    int findMin(vector<int>& x) {
        int n = x.size();
        int low = 0,  high = n-1;
        while(low<high){
            int mid = (low+high)/2;
            if(x[mid]>x[high]){
                low = mid +1;
            }
            else {
                high = mid;
            }
            
        }
        return x[low];
    }
};