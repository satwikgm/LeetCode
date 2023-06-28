//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(vector<int> &arr , int k)
    {
        vector<int> m(arr.size()+1 , 0);
        int i=0;
        int ans=0;
        int unique=0;
        for(int j=0;j<arr.size();j++)
        {
            m[arr[j]]++;
            if(m[arr[j]] == 1)
            {
                unique++;
            }
            while(unique > k)
            {
                m[arr[i]]--;
                if(m[arr[i]] == 0)
                {
                    unique--;
                }
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) 
    {
        return fun(arr,k)-fun(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends