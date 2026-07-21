class Solution {
public:
    vector<string> ans;

    vector<string> phone = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(int index, string &digits, string &path)
    {
        if(index == digits.size())
        {
            ans.push_back(path);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for(char ch : letters)
        {
            path.push_back(ch);

            solve(index + 1, digits, path);

            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        string path;

        solve(0, digits, path);

        return ans;
    }
};