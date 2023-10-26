class Solution {
public:
    #define ll long long
    const int mod = 1e9+7;
    ll fun(ll x , ll n) {
        if(n==0) return 1;
        ll ans = fun(x,n/2)%mod;
        ans = ans*ans;
        ans = ans%mod;
        if(n%2) ans=ans*x;
        ans = ans%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll ev = n/2+n%2;
        ll od = n/2;
        return (fun(5,ev)*fun(4,od))%mod;
    }
};