//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool fun(vector<int> &stations , int k , double m)
    {
        // int ctr=0;
        for(int i=1;i<stations.size();i++)
        {
            k -= (int)((stations[i] - stations[i-1])/m);
        }
        return k>=0;
    }
    double findSmallestMaxDist(vector<int> &stations, int K)
    {
        double ans;
        double l=0,h=1e9;
        while(h-l>=1e-6)
        {
            double m = ((double)l+(double)h)/2.0;
            if(fun(stations , K , m))
            {
                ans=m;
                h=m;
            }
            else
            {
                l=m;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends