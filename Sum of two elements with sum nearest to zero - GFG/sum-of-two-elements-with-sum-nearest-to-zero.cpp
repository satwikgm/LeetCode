//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int l=0,h=n-1;
            int absans=1e9;
            int ans=1e9;
            while(l<h)
            {
                int sum=arr[l]+arr[h];
                int diff = abs(sum);
                if(diff==absans)
                {
                    if(sum>=0)
                    {
                        ans=sum;
                    }
                }
                if(absans>diff)
                {
                    absans=diff;
                    ans=sum;
                }
                if(sum>0)
                {
                    h--;
                }
                else if(sum<0)
                {
                    l++;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends