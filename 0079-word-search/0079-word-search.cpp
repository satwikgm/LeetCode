class Solution {
public:
    vector<vector<bool>> vis;
    bool fun(vector<vector<char>> &board, string word, int i, int j, int ind)
    {
        int n=board.size();
        int m=board[0].size();
        if(board[i][j] == word[ind])
        {
            vis[i][j]=1;
            if(ind==word.size()-1)
            {
                return 1;
            }
            if(i-1>=0 && !vis[i-1][j])
            {
                if(fun(board,word,i-1,j,ind+1))
                {
                    return 1;
                }
            }
            if(j-1>=0 && !vis[i][j-1])
            {
                if(fun(board,word,i,j-1,ind+1))
                {
                    return 1;
                }
            }
            if(i+1<n && !vis[i+1][j])
            {
                if(fun(board,word,i+1,j,ind+1))
                {
                    return 1;
                }
            }
            if(j+1<m && !vis[i][j+1])
            {
                if(fun(board,word,i,j+1,ind+1))
                {
                    return 1;
                }
            }
            // Backtrack
            vis[i][j]=0;
            // return 0;
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i=0; i<n; i++)
        {    
            for(int j=0; j<m; j++)
            {
                if(fun(board, word, i, j, 0))
                {
                    return true;   
                }
            }
        }
        return false;
    }
};