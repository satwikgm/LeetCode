//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int memo[1001][1001];
	int fun(string s1, string s2 , int m , int n)
	{
	    if(m==0) return n;
	    if(n==0) return m;
	    if(memo[m][n] != -1)
	        return memo[m][n];
	    if(s1[m-1]==s2[n-1]) return memo[m][n] = fun(s1,s2,m-1,n-1);
	    return memo[m][n] =  1+min(fun(s1,s2,m,n-1),fun(s1,s2,m-1,n));
	}
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    memset(memo,-1,sizeof(memo));
	    return fun( s1, s2 , s1.size() , s2.size());
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends