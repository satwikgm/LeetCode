//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s;
        for(int i=0;i<N;i++)
        {
            s.insert(arr[i]);
        }
        int ans=0,temp_ans=0;
        int curr_num=0,curr_streak=0;
        for(int i=0;i<N;i++)
        {
            if(s.find(arr[i] - 1) == s.end())
            {
                curr_num=arr[i];
                curr_streak=1;
            }
            while(s.find(curr_num+1) != s.end())
            {
                curr_streak += 1;
                curr_num += 1;
            }
            ans=max(ans,curr_streak);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends