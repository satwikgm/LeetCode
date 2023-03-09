//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool fun(int a[] , int m , int k , int N)
    {
        int sum=0;
        int cnt=1;
        for(int i=0;i<N;i++)
        {
            if(sum+a[i] > m)
            {
                cnt++;
                sum=0;
            }
            sum+=a[i];
        }
        return cnt<=k;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
        {
            return -1;
        }
        int l=A[0],h=0,m,ans;
        for(int i=0;i<N;i++)
        {
            l=max(l,A[i]);
            h+=A[i];
        }
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(A,m,M,N))
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
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends