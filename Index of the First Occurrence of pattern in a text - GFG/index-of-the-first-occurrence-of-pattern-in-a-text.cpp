//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) 
    {
        for(int i=0;i<text.size();i++)
        {
            int j;
            for(j=0;j<pat.size();j++)
            {
                if(pat[j] != text[i+j])
                {
                    break;
                }
            }
            if(j==pat.size())
            {
                return i;
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
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends