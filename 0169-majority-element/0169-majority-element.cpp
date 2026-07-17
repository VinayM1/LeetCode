class Solution {
public:
    int majorityElement(vector<int>& x) {
        sort(x.begin(), x.end());
        return x[x.size()/2];
        }
    
};