class Solution {
public:
    int mod=1e9+7;
    long long power(long long x , long long y)   // To compute x^y recursively  
    {
        if(y==0)
        {
            return 1;
        }
        long long ans=power(x,y/2);
        if(y%2)
        {
            ans=((ans*ans)%mod*x)%mod;
        }
        else
        {
            ans=(ans*ans)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) 
    {
        long long e = n/2+n%2;
        long long o = n/2;
        return (power(5,e)*power(4,o))%mod;
    }
};