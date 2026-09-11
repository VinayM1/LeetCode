class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();
        set<int> st;

        for(int i = 0; i < n; i++) {

            // First digit cannot be 0
            if(digits[i] == 0) {
                continue;
            }

            for(int j = 0; j < n; j++) {

                // Same digit copy cannot be used twice
                if(j == i) {
                    continue;
                }

                for(int k = 0; k < n; k++) {

                    if(k == i || k == j) {
                        continue;
                    }

                    // Last digit must be even
                    if(digits[k] % 2 != 0) {
                        continue;
                    }

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};