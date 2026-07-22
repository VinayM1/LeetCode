class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    bool isSafe(int row, int col , int n){
         int r = row;
         int c = col;
        while(r>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
        }
         r = row;
         c = col;
        while(r>= 0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
         r = row;
         c = col;
        while(r>=0 && c<n){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
    void dfs(int row,  int n ){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0 ; col<n ; col++){
            if(isSafe(row,col,n)){
                board[row][col] = 'Q';
                dfs(row+1,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        dfs(0,n);
        return ans;

    }
};