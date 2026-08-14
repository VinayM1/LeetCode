class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>hash;
        int n = s.size();
        int left = 0, right = 0;
        int Maxlen = 0;
        while(right<n){
            hash[s[right]]++;
            if(hash[s[right]] != -1){
            while(hash[s[right]]>2){
                hash[s[left]]--;
                left++;
            }
            
            int len = (right-left+1);
            Maxlen = max(len,Maxlen);
            right++;
            

        }
        
        }
        return Maxlen;
    }
};