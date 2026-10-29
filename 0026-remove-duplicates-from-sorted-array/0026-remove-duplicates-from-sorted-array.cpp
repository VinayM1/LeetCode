class Solution {
public:
    int removeDuplicates(vector<int>& x) {

        int i = 0;
        int j = 1;
        int n = x.size();
        while(j<n){
            if(x[i] != x[j]){
                i++;
                x[i] = x[j];

            }
            j++;
        
        }
        return i+1;


        
    }
};