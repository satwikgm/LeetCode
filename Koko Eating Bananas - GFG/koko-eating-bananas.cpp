//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fun(vector<int> &piles , int m , int h)
    {
        int hrs=0;
        for(int i=0;i<piles.size();i++)
        {
            int rem=piles[i]/m;
            hrs += rem;
            if(piles[i]%m)
            {
                hrs+=1;
            }
        }
        return hrs<=h;
    }
    int Solve(int N, vector<int>& piles, int H) 
    {
        int l=1,h=1e9,m,ans;
        while(l<=h)
        {
            m=(l+h)/2;
            if(fun(piles,m,H))
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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends