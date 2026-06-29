class Solution {
public:
    string longestCommonPrefix(vector<string>& x) {
        string y = "";
        for(int i=0;i<x[0].length();i++){
            for(int j=0;j<x.size()-1;j++){
                if(x[j][i] != x[j+1][i]) return y;

               
            }
             y+=x[0][i];
        }
        return y;
        
    }
    
};