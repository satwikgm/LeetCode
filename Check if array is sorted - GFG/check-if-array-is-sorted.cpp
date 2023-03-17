//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool fun(int arr[] , int n , int ind)
    {
        if(n==0 || n==1 || ind==n-1)
        {
            return 1;
        }
        return arr[ind]<=arr[ind+1] && fun(arr,n,ind+1);
    }
    bool arraySortedOrNot(int arr[], int n) 
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        return fun(arr,n,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends