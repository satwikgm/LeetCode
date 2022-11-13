//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	void swap(vector<int> &a , int i , int j)
	{
	    int t = a[i];
	    a[i] = a[j];
	    a[j] = t;
	}
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<int> a = nums;
	    sort(a.begin(),a.end());
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	        m[nums[i]]=i;
	    }
	    int c=0;
	    for(int i=0;i<n;i++)
	    {
	        if(nums[i] != a[i])
	        {
	            int x = nums[i];
	            c++;
	            swap(nums , i , m[a[i]]);
	            m[x] = m[a[i]];
	        }
	    }
	    return c;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends