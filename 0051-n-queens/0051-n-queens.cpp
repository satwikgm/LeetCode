class Solution {
public:
    bool isSafe(int row , int col , vector<string> &board , int n)
    {
        // Upper diagonal
        int tempRow=row;
        int tempCol=col;
        while(row >= 0 && col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return 0;
            }
            row--;
            col--;
        }
        // Lower Diagonal
        row = tempRow;
        col = tempCol;
        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return 0;
            }
            row++;
            col--;
        }
        // Left
        row = tempRow;
        col = tempCol;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return 0;
            }
            col--;
        }
        return true;
    }
    void fun(int col , vector<string> &board , vector<vector<string>> &ans , int n)
    {
        if(col == n)
        {
            ans.push_back(board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == '.')
            {
                if(isSafe(i,col,board,n))
                {
                    board[i][col] = 'Q';
                    fun(col+1,board,ans,n);
                    board[i][col] = '.';
                }
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board;
        string init(n,'.');
        for(int i=0;i<n;i++)
        {
            board.push_back(init);
        }
        // col
        fun(0 , board , ans , n);
        return ans;
    }
};