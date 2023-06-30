//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int i , int j , vector<string> board)
    {
        int n=board.size();
        int row=i , col = j;
        // upper diagonal
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q')
            {
                return 0;
            }
            i--;
            j--;
        }
        i=row,j=col;
        // Lower Diagonal
        while(i<n && j>=0)
        {
            if(board[i][j] == 'Q')
            {
                return 0;
            }
            i++;
            j--;   
        }
        i=row,j=col;
        while(j>=0)
        {
            if(board[i][j] == 'Q')
            {
                return 0;
            }
            j--;    
        }
        return 1;
    }
    void fun(int col , vector<vector<int>> &ans , vector<int> v , vector<string> board , int n)
    {
        if(col == n)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == '.')
            {
                if(isSafe(i,col,board))
                {
                    board[i][col]='Q';
                    v.push_back(i+1);
                    fun(col+1,ans,v,board,n);
                    board[i][col]='.';
                    v.pop_back();
                }
            }
        }
    }
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board.push_back(s);
        }
        fun(0,ans,v,board,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends