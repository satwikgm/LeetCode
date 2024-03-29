//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        vector<long long int> ans;
        long long int x = 0;
        for (long long int i = 0; i < N; i++)
        {
            x ^= Arr[i];
        }
        long long int diff = x & ~(x - 1);
        long long int num1 = 0, num2 = 0;
        for (long long int i = 0; i < N; i++)
        {
            if (Arr[i] & diff)
            {
                num1 ^= Arr[i];
            }
            else
            {
                num2 ^= Arr[i];
            }
        }
        ans.push_back(num1);
        ans.push_back(num2);
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends