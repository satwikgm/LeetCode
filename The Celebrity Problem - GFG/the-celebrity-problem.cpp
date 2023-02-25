//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        if(n==1)
        {
            return -1;
        }
        vector<int> know(n,0);
        bool fl=0 , fl2=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            fl=0;
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    know[j]++;
                    fl=1;
                }
            }
            if(fl==0)
            {
                fl2=1;
                c++;
            }
        }
        if(!fl2 || c>=2)
        {
            return -1;
        }
        
        int ans=-1;
        int res=INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(know[i]>ans)
            {
                ans=know[i];
                res=i;
            }
        }
        if(res==INT_MAX)
        {
            return -1;
        }
        
        return res ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends