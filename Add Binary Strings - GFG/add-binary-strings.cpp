//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int i = A.size()-1 , j = B.size()-1 , c=0;
	    string res="";
	    while(i>=0 || j>=0 || c)
	    {
	        if(i>=0)
	        {
	            c += A[i]-'0';
	            i--;
	        }
	        if(j>=0)
	        {
	            c += B[j]-'0';
	            j--;
	        }
	        res += (c%2+'0');
	        c /= 2;
	    }
	    reverse(res.begin(),res.end());
	    string ans="";
	    i=0;
	    while(res[i]!='1')
	    {
	        i++;
	    }
	    for(int j=i;j<res.size();j++)
	    {
	        ans+=res[j];
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends