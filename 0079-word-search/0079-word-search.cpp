class Solution {
public:
    bool vis[7][7];
    // memset(vis,0,sizeof(vis));
    bool fun(vector<vector<char>>& board , int i , int j , string word , int ind)
    {
        int m=board.size();
        int n=board[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        if(board[i][j] == word[ind])
        {
            vis[i][j]=1;
            if(ind == word.size()-1)
            {
                return 1;
            }
            for(int k=0;k<4;k++)
            {
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc])
                {
                    if(fun(board,nr,nc,word,ind+1)) {
                        return 1;
                    }   
                }
            }
            vis[i][j]=0;
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(fun(board,i,j,word,0)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};