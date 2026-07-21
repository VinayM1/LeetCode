class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string &s, int left , int right ){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int index , string &s ,vector<string>& subset ){
        if(index == s.size()){
            ans.push_back(subset);
        }
        for(int i = index;i<s.size();i++){
            if(palindrome(s,index,i)){
                subset.push_back(s.substr(index,i-index+1));
                solve(i+1,s,subset);
                subset.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> subset;
        solve(0,s,subset);
        return ans;
    }
};