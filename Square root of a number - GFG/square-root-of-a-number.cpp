//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int l=0,h=x,m,ans;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m*m==x)
            {
                return m;
            }
            else if(m*m>x)
            {
                h=m-1;
            }
            else
            {
                l=m+1;
                ans=m;
            }
        }
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends