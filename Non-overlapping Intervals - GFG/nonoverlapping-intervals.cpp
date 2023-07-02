//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comp(vector<int> &v1 , vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals) 
    {
        int ans=0;
        sort(intervals.begin(),intervals.end() , comp);
        int prev_end = intervals[0][1];
        for(int i=1;i<N;i++)
        {
            if(intervals[i][0] >= prev_end)
            {
                prev_end = intervals[i][1];
            }
            else
            {
                ans++;
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends