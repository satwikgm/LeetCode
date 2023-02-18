//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y)
    {
        int ans=-1;
        bool visited[N][M];
        memset(visited,0,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({x-1,y-1});
        while(!q.empty())
        {
            ans++;
            int count = q.size();
            for(int k=0;k<count;k++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                visited[i][j]=1;
                if(i-1>=0 && !visited[i-1][j])
                {
                    visited[i-1][j]=1;
                    q.push({i-1,j});
                }
                if(i+1<N && !visited[i+1][j])
                {
                    visited[i+1][j]=1;
                    q.push({i+1,j});
                }
                if(j-1>=0 && !visited[i][j-1])
                {
                    visited[i][j-1]=1;
                    q.push({i,j-1});
                }
                if(j+1<M && !visited[i][j+1])
                {
                    visited[i][j+1]=1;
                    q.push({i,j+1});
                }
            }
        }
        return max(0,ans);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends