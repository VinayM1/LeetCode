class Solution {
public:
    bool Solve(string s,int i,int count,vector<vector<int>>& dp){
        int n = s.size();
        if(count<0){
            return false;
        }
        if(i == n){
            return count == 0;
        }
        if(dp[i][count] != -1){
            return dp[i][count];
        }

            if(s[i] == '('){
                return dp[i][count] = Solve(s,i+1,count+1,dp);
            }
            if(s[i] == ')'){
                return dp[i][count] = Solve(s,i+1,count-1,dp);
            }
            if (s[i] == '*'){
                return dp[i][count] = Solve(s,i+1,count+1,dp) || Solve(s,i+1,count-1,dp) || Solve(s,i+1,count,dp);
            }
            return false;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int count = 0;
        return Solve(s,0,count,dp);
    }
};