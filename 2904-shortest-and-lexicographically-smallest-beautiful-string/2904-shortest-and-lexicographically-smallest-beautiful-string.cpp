class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int right = 0;
        int count = 0;

        string ans = "";

        while(right < n) {

            if(s[right] == '1') {
                count++;
            }

            while(count == k) {

                string curr = s.substr(left, right - left + 1);

                if(ans == "" || curr.size() < ans.size()) {
                    ans = curr;
                }
                else if(curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }

                if(s[left] == '1') {
                    count--;
                }

                left++;
            }

            right++;
        }

        return ans;
    }
};