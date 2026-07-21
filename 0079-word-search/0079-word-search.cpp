class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             string &word,
             int row,
             int col,
             int index)
    {
        // 1. Out of bounds
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size())
            return false;

        // 2. Character doesn't match
        if(board[row][col] != word[index])
            return false;

        // 3. Entire word matched
        if(index == word.size()-1)
            return true;

        // 4. Save current character
        char temp = board[row][col];

        // 5. Mark visited
        board[row][col] = '#';

        // 6. Explore 4 directions
        bool found =
            dfs(board,word,row+1,col,index+1) ||   // Down
            dfs(board,word,row-1,col,index+1) ||   // Up
            dfs(board,word,row,col+1,index+1) ||   // Right
            dfs(board,word,row,col-1,index+1);     // Left

        // 7. Backtrack
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as starting point
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};