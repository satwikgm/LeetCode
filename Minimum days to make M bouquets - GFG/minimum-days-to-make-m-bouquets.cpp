//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n=bloomDay.size();
        if((long long)m*(long long)k>(long long)n)
        {
            return -1;
        }
        int low=1 , high=1e9;
        int ans,mid;
        while(low<=high)
        {
            mid=(low)+(high-low)/2;
            int cnt=0,num=0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i] <= mid)
                {
                    cnt++;
                }
                else
                {
                    cnt=0;
                    continue;
                }
                if(cnt%k==0)
                {
                    num++;
                    cnt=0;
                }
            }
            if(num>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int solve(int M, int K, vector<int> &bloomDay){
      return minDays(bloomDay,M,K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends