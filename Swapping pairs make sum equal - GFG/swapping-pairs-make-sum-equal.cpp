//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            s1+=A[i];
        }
        for(int i=0;i<m;i++)
        {
            s2+=B[i];
        }
        if((s1+s2)%2)
        {
            return -1;
        }
        if(s1==s2)
        {
            return 1;
        }
        int x = abs(s1-s2)/2;
        unordered_map<int,int> mp;
        if(s1>s2)
        {
            for(int i=0;i<n;i++)
            {
                mp[A[i]]++;
            }
            for(int i=0;i<m;i++)
            {
                if(mp.find(B[i]+x)!=mp.end())
                {
                    return 1;
                }
            }
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                mp[B[i]]++;
            }
            for(int i=0;i<n;i++)
            {
                if(mp.find(A[i]+x)!=mp.end())
                {
                    return 1;
                }
            }
        }
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends