//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define pi pair<int,int>
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        vector<int> dist(100000,1e9);
        dist[start]=0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,start});
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int ops = p.first;
            if(node==end)
            {
                return ops;
            }
            for(auto it : arr)
            {
                int num = node*it;
                num%=100000;
                if(dist[num] > ops+1)
                {
                    dist[num] = ops+1;
                    if(num==end)
                    {
                        return ops+1;
                    }
                    pq.push({dist[num],num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends