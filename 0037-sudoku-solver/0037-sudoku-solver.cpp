class Solution {
public:
    bool canPlace(vector<vector<char>>& board , int row , int col , char c)
    {
        for(int row=0;row<9;row++)
        {
            if(board[row][col] == c)
            {
                return 0;
            }
        }
        for(int col=0;col<9;col++)
        {
            if(board[row][col] == c)
            {
                return 0;
            }
        }
        int x = row/3;
        int y = col/3;
        for(int row = 3*x;row<3*x+3;row++)
        {
            for(int col=3*y;col<3*y+3;col++)
            {
                if(board[row][col] == c)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool fun(vector<vector<char>>& board)
    {
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col] == '.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(canPlace(board,row,col,c))
                        {
                            board[row][col]=c;
                            if(fun(board))
                            {
                                return 1;
                            }
                            board[row][col]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        fun(board);
    }
};