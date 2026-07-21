class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index,int k , int n , int sum,  vector<int> subset ){
        if(k==subset.size() && sum == n){
            ans.push_back(subset); 
            return;
        }
        if(subset.size()>k){
            return;
        }
        
        for(int i = index ;  i<=9 ;i++){
            subset.push_back(i);
            solve(i+1,k,n,sum+i,subset);
            subset.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        solve(1,k,n,0,subset);
        return ans;
    }
};