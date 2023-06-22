//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int sum=0;
        int ans=0;
        map<int,int> m;
        for(int i=0;i<N;i++)
        {
            sum += A[i];
            if(sum == K)
            {
                ans = max(ans , i+1);
            }
            int rem = sum-K;
            if(m.find(rem) != m.end())
            {
                int len = i-m[rem];
                ans=max(ans,len);
            }
            if(m.find(sum) == m.end())
            {
                m[sum]=i;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends