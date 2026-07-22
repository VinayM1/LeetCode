class Solution {
public:
    vector<string> ans;

    bool isMatch(string word, vector<string>& wordDict)
    {
        for(int i = 0; i < wordDict.size(); i++)
        {
            if(wordDict[i] == word)
            {
                return true;
            }
        }

        return false;
    }

    void dfs(string &s,
             vector<string>& wordDict,
             int index,
             vector<string>& subset)
    {
        // Entire string used
        if(index == s.size())
        {
            string sentence = "";

            for(int i = 0; i < subset.size(); i++)
            {
                sentence += subset[i];

                if(i != subset.size() - 1)
                {
                    sentence += " ";
                }
            }

            ans.push_back(sentence);
            return;
        }

        for(int i = index; i < s.size(); i++)
        {
            string word = s.substr(index, i - index + 1);

            if(isMatch(word, wordDict))
            {
                subset.push_back(word);

                dfs(s, wordDict, i + 1, subset);

                subset.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> subset;

        dfs(s, wordDict, 0, subset);

        return ans;
    }
};