//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<bool>> vis;
    bool fun(vector<vector<char>> &board, string word, int i, int j, int ind)
    {
        int n=board.size();
        int m=board[0].size();
        if(board[i][j] == word[ind])
        {
            vis[i][j] = true;
            if(ind == word.size() - 1)
            {
                return 1;   
            }
            if(i-1 >= 0 && vis[i-1][j] == false)
            {
                if(fun(board, word, i-1, j, ind+1))
                    return true;
            }
                
            if(i+1 < n && vis[i+1][j] == false)
            {
                if(fun(board, word, i+1, j, ind+1))
                    return true;
            }
            if(j-1 >= 0 && vis[i][j-1] == false)
            {
                if(fun(board, word, i, j-1, ind+1))
                    return true;
            }
            if(j+1 < m && vis[i][j+1] == false)
            {
                if(fun(board, word, i, j+1, ind+1))
                    return true;
            }
            vis[i][j] = false;
            return false;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends