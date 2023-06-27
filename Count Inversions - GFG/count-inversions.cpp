//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans = 0;
    void mergeSort(long long arr[] , long long l , long long r)
    {
        if(l>=r)
        {
            return;
        }
        long long m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    void merge(long long arr[] , long long l , long long m , long long r)
    {
        int i=l,j=m+1;
        vector<long long> temp;
        while(i<=m && j<=r)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            // right is smaller
            else
            {
                ans += m-i+1;
                temp.push_back(arr[j++]);
            }
        }
        while(i<=m)
        {
            temp.push_back(arr[i++]);
        }
        while(j<=r)
        {
            temp.push_back(arr[j++]);
        }
        for(int i=l;i<=r;i++)
        {
            arr[i] = temp[i-l];
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends