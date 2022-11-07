//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> ans;
	    void permute(string s , int l , int r)
	    {
	        if(l==r)
	        {
	            ans.insert(s);
	        }
	        else
	        {
	            for(int i=l;i<=r;i++)
	            {
	                swap(s[i],s[l]);
	                permute(s,l+1,r);
	                swap(s[i],s[l]);
	            }   
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> v;
		    permute(S,0,S.size()-1);
		    for(auto it : ans)
		    {
		        v.push_back(it);
		    }
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends