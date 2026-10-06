class Solution {
public:
    int minAddToMakeValid(string s) {

        int count = 0;   // number of '('
        int count1 = 0;  // number of ')'
        int ans = 0;

        for (char c : s) {

            if (c == '(') {
                count++;
            }
            else {
                count1++;

               
                if (count1 > count) {
                    ans++;   
                    count++; 
                }
            }
        }

        
        ans += count - count1;

        return ans;
    }
};