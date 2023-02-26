//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPrime(long long n)
    {
        if(n==2 || n==3)
        {
            return 1;
        }
        if(n%2==0 || n%3==0)
        {
            return 0;
        }
        for(int i=5;i<=sqrt(n);i+=6)
        {
            if(n%(i)==0 || n%(i+2)==0)
            {
                return 0;
            }
        }
        return 1;
    }
    long long primeProduct(long long L, long long R)
    {
        long long ans=1;
        long long mod = 1e9+7;
        for(long long i=L;i<=R;i++)
        {
            if(isPrime(i))
            {
                ans=(ans%mod)*(i%mod)%(mod);
            }
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends