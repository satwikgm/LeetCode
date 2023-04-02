//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void fun(vector<string> &ans , string s , int m , int n)
    {
        if(m==0 && n==0)
        {
            ans.push_back(s);
            return;
        }
        if(m==n)
        {
            fun(ans , s+'(' , m-1 , n);
        }
        else if(!m)
        {
            fun(ans , s+')' , m , n-1);
        }
        else
        {
            // pick (
            fun(ans , s+'(' , m-1,n);
            // pick )
            fun(ans , s+')' , m , n-1);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s = "";
        fun(ans,s,n,n);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends