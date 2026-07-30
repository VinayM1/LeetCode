class Solution {
public:
    unordered_map<string, int> level;
    vector<vector<string>> ans;

    void dfs(string word, string beginWord, vector<string>& path)
    {
        if(word == beginWord)
        {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = level[word];

        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if(level.find(word) != level.end() &&
                   level[word] + 1 == steps)
                {
                    path.push_back(word);
                    dfs(word, beginWord, path);
                    path.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 1;

        st.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            q.pop();

            int steps = level[word];

            if(word == endWord)
                break;

            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(st.find(word) != st.end())
                    {
                        q.push(word);
                        level[word] = steps + 1;
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if(level.find(endWord) == level.end())
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};