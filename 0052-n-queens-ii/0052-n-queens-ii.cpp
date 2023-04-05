class Solution {
public:
    bool canPlace(int row , int col , vector<string> &board , int n)
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
    void fun(int col , vector<string> board , int &ans , int n)
    {
        if(col == n)
        {
            ans += 1;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == '.')
            {
                if(canPlace(i , col , board , n))
                {
                    board[i][col] = 'Q';
                    fun(col+1 , board , ans , n);
                    board[i][col] = '.';    // Backtrack
                }
            }
        }
    }
    int totalNQueens(int n) 
    {
        vector<string> board;
        string init(n,'.');
        for(int i=0;i<n;i++)
        {
            board.push_back(init);
        }
        int ans=0;
        // ind , board ,  number
        fun(0 , board , ans , n);
        return ans;
    }
};