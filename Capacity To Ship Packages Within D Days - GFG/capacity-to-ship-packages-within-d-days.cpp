//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool fun(int weights[] , int n , int m , int days)
    {
        int d=1;
        int wt=0;
        for(int i=0;i<n;i++)
        {
            if(wt+weights[i] > m)
            {
                d++;
                wt=0;
            }
            wt += weights[i];
        }
        if(d > days)
        {
            return 0;
        }
        return 1;
    }
    int shipWithinDays(int weights[] , int n , int days) 
    {
        int l=0,h=0;
        int m;
        for(int i=0;i<n;i++)
        {
            l=max(l,weights[i]);
            h+=weights[i];
        }
        int ans=h;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(weights,n,m,days))
            {
                ans=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
    int leastWeightCapacity(int arr[], int N, int D) 
    {
        return shipWithinDays(arr,N,D);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends