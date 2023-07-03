//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findMin(int arr[] , int n)
    {
        int l=0,h=n-1,ans=INT_MAX,idx;
        while(l<=h)
        {
            int m=(l+h)/2;
            // left sorted
            if(arr[m] >= arr[l])
            {
                if(ans >= arr[l])
                {
                    ans = min(ans , arr[l]);
                    idx=l;
                }
                l=m+1;
            }
            else
            {
                if(ans > arr[m])
                {
                    ans = arr[m];
                    idx=m;
                }
                h=m-1;
            }
        }
        
        return idx;
    }
	int findKRotation(int arr[], int n) 
	{
	    return findMin(arr,n);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends