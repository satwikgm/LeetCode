//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        int ans=0;
        unordered_map<int,int> m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(m.find(sum) == m.end())
            {
                m[sum] = i;
            }
            else
            {
                ans = max(ans , i-m[sum]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends