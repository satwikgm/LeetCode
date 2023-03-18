//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void fun(int ind , vector<int> &arr , vector<vector<int>> &ans , vector<int> &v)
    {
        if(ind==arr.size())
        {
            ans.push_back(v);
            return;
        }
        // not pick
        fun(ind+1,arr,ans,v);
        
        // pick
        v.push_back(arr[ind]);
        fun(ind+1,arr,ans,v);
        v.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        vector<int> v;
        fun(0,A,ans,v);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends